/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006 Marco Bianchetti
 Copyright (C) 2006 Silvia Frasson
 Copyright (C) 2006 Mario Pucci
 Copyright (C) 2006 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/MarketModels/driftcalculator.hpp>
#include <ql/MarketModels/duffsdeviceinnerproduct.hpp>

namespace QuantLib {

    DriftCalculator::DriftCalculator(const Matrix& pseudo,
                                     const std::vector<Spread>& displacements,
                                     const std::vector<Time>& taus,
                                     Size numeraire,
                                     Size alive)
    : dim_(taus.size()), factors_(pseudo.columns()),
      isFullFactor_(factors_==dim_ ? true : false),
      numeraire_(numeraire), alive_(alive),
      displacements_(displacements), oneOverTaus_(taus.size()),
      pseudo_(pseudo), tmp_(taus.size(), 0.0),
      e_(pseudo_.columns(), pseudo_.rows(), 0.0),
      downs_(taus.size()), ups_(taus.size()) {

        // Check requirements
        QL_REQUIRE(dim_>0, "Dim out of range");
        QL_REQUIRE(displacements.size() == dim_,
            "Displacements out of range");
        QL_REQUIRE(pseudo.rows()==dim_,
            "pseudo.rows() not consistent with dim");
        QL_REQUIRE(pseudo.columns()>0 && pseudo.columns()<=dim_,
            "pseudo.rows() not consistent with pseudo.columns()");
        QL_REQUIRE(alive>=0 && alive<dim_, "Alive out of bounds");
        QL_REQUIRE(numeraire_<=dim_, "Numeraire larger than dim");
        QL_REQUIRE(numeraire_>=alive, "Numeraire smaller than alive");

        // Precompute 1/taus
        for (Size i=0; i<taus.size(); ++i)
            oneOverTaus_[i] = 1.0/taus[i];

        // Compute covariance matrix from pseudoroot
        const Disposable<Matrix> pT = transpose(pseudo_);
        C_ = pseudo_*pT;

        // Compute lower and upper extrema for (non reduced) drift calculation
        for (Size i=alive_; i<dim_; ++i) {
            downs_[i] = std::min(i+1, numeraire_);
            ups_[i]   = std::max(i+1, numeraire_);
        }
    }

    void DriftCalculator::compute(const std::vector<Rate>& forwards,
                                  std::vector<Real>& drifts) const {
        #if defined(QL_EXTRA_SAFETY_CHECKS)
            QL_REQUIRE(forwards.size()==dim_, "forwards.size() <> dim");
            QL_REQUIRE(drifts.size()==dim_, "drifts.size() <> dim");
        #endif

        if (isFullFactor_)
            computePlain(forwards, drifts);
        else
            computeReduced(forwards, drifts);
    }

    void DriftCalculator::computePlain(const std::vector<Rate>& forwards,
                                       std::vector<Real>& drifts) const {

        // Compute drifts without factor reduction,
        // using directly the covariance matrix.

        // Precompute forwards factor
        Size i;
        for(i=alive_; i<dim_; ++i)
            tmp_[i] = (forwards[i]+displacements_[i]) /
                      (oneOverTaus_[i]+forwards[i]);
        // Compute drifts
        for (i=alive_; i<dim_; ++i) {
            drifts[i] = std::inner_product(tmp_.begin()+downs_[i],
                                           tmp_.begin()+ups_[i],
                                           C_.row_begin(i)+downs_[i], 0.0);
            if (numeraire_>i+1)
                drifts[i] = -drifts[i];
        }
    }

    void DriftCalculator::computeReduced(const std::vector<Rate>& forwards,
                                         std::vector<Real>& drifts) const {

        // Compute drifts with factor reduction,
        // using the pseudo square root of the covariance matrix.

        // Precompute forwards factor
        for (Size i=alive_; i<dim_; ++i)
            tmp_[i] = (forwards[i]+displacements_[i]) /
                (oneOverTaus_[i]+forwards[i]);

        // Enforce initialization
        for (Size r=0; r<factors_; ++r)
            e_[r][std::max(0,static_cast<Integer>(numeraire_)-1)] = 0.0;

        // Now compute drifts: take the numeraire P_N (numeraire_=N)
        // as the reference point, divide the summation into 3 steps,
        // et impera:

        // 1st step: the drift corresponding to the numeraire P_N is zero.
        // (if N=0 no drift is null, if N=dim_ the last drift is null).
        if (numeraire_>0) drifts[numeraire_-1] = 0.0;

        // 2nd step: then, move backward from N-2 (included) back to
        // alive (included) (if N=0 jumps to 3rd step, if N=dim_ the
        // e_[r][N-1] are correctly initialized):

        for (Integer i=static_cast<Integer>(numeraire_)-2;
             i>=static_cast<Integer>(alive_); --i) {
            drifts[i] = 0.0;
            for (Size r=0; r<factors_; ++r) {
                e_[r][i] = e_[r][i+1] + tmp_[i+1] * pseudo_[i+1][r];
                drifts[i] -= e_[r][i]*pseudo_[i][r];
            }

            /*
            Matrix::column_iterator p1 = e_.column_begin(i);
            Matrix::column_iterator end = e_.column_end(i);
            Matrix::const_column_iterator p2 = e_.column_begin(i+1);
            Matrix::const_row_iterator q1 = pseudo_.row_begin(i);
            Matrix::const_row_iterator q2 = pseudo_.row_begin(i+1);
            Real x = tmp_[i+1];
            while (p1 != end) {
                *p1 = *p2 + x*(*q2);
                drifts[i] -= *p1*(*q1);
                ++p1; ++p2; ++q1; ++q2;
            }
            */
        }
        
        // 3rd step: now, move forward from N (included) up to n (excluded)
        // (if N=0 this is the only relevant computation):
        for (Size i=numeraire_; i<dim_; ++i) {
            drifts[i] = 0.0;
            for (Size r=0; r<factors_; ++r) {
                if (i==0) {
                    e_[r][i] = tmp_[i] * pseudo_[i][r];
                } else {
                    e_[r][i] = e_[r][i-1] + tmp_[i] * pseudo_[i][r];
                }
                drifts[i] += e_[r][i]*pseudo_[i][r];
            }
        }
    }

}
