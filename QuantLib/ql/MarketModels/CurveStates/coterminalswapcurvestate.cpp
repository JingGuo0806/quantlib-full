/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Marco Bianchetti
 Copyright (C) 2007 Cristina Duminuco

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

#include <ql/MarketModels/CurveStates/coterminalswapcurvestate.hpp>

namespace QuantLib {

    CoterminalSwapCurveState::CoterminalSwapCurveState(const std::vector<Time>& rateTimes)
    : NewCurveState(rateTimes),
      first_(nRates_),
      discRatios_(nRates_+1, 1.0),
      forwardRates_(nRates_),
      cmSwapRates_(nRates_), cmSwapAnnuities_(nRates_,taus_[nRates_-1]),
      cotSwapRates_(nRates_), cotAnnuities_(nRates_, taus_[nRates_-1]) {}

      void CoterminalSwapCurveState::setOnCoterminalSwapRates(
                                        const std::vector<Rate>& rates,
                                        Size firstValidIndex) {
            QL_REQUIRE(rates.size()==nRates_,
                       "rates mismatch: " <<
                       nRates_ << " required, " <<
                       rates.size() << " provided");
            QL_REQUIRE(firstValidIndex<nRates_,
                       "first valid index must be less than " <<
                       nRates_ << ": " <<
                       firstValidIndex << " not allowed");

        // first copy input...
        first_ = firstValidIndex;
        std::copy(rates.begin()+first_, rates.end(),
                  cotSwapRates_.begin()+first_);
        // ...then calculate discount ratios and annuities
        
        // taken care at constructor time
        //discRatios_[nRates_] = 1.0;
        cotAnnuities_[nRates_] = taus_[nRates_];

        // j < n
        for (Size i=nRates_; i>first_; --i) {
            discRatios_[i] = 1.0 + cotSwapRates_[i] * cotAnnuities_[i];
            cotAnnuities_[i-1] = cotAnnuities_[i] + taus_[i] * discRatios_[i];            
        }
        discRatios_[first_] = 1.0 + cotSwapRates_[first_] * cotAnnuities_[first_]; 

        // lazy evaluation of:
        // - forward rates
        // - constant maturity swap rates/annuities
    }

    Real CoterminalSwapCurveState::discountRatio(Size i, Size j) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(std::min(i, j)>=first_, "invalid index");
        QL_REQUIRE(std::max(i, j)<=nRates_, "invalid index");
        return discRatios_[i]/discRatios_[j];
    }

    Rate CoterminalSwapCurveState::forwardRate(Size i) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(i>=first_ && i<=nRates_, "invalid index");
        forwardsFromDiscountRatios(first_, discRatios_, taus_, forwardRates_);
        return forwardRates_[i];
    }

    Rate CoterminalSwapCurveState::coterminalSwapAnnuity(Size numeraire,
                                                         Size i) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(numeraire>=first_ && numeraire<=nRates_,
                  "invalid numeraire");
        QL_REQUIRE(i>=first_ && i<=nRates_, "invalid index");
        return cotAnnuities_[i]/discRatios_[numeraire];
    }

    Rate CoterminalSwapCurveState::coterminalSwapRate(Size i) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(i>=first_ && i<=nRates_, "invalid index");
        return cotSwapRates_[i];
    }

    Rate CoterminalSwapCurveState::cmSwapAnnuity(Size numeraire,
                                                 Size i,
                                                 Size spanningForwards) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(numeraire>=first_ && numeraire<=nRates_,
                   "invalid numeraire");
        QL_REQUIRE(i>=first_ && i<=nRates_, "invalid index");

        // consider lazy evaluation here
        constantMaturityFromDiscountRatios(spanningForwards, first_,
                                           discRatios_, taus_,
                                           cmSwapRates_, cmSwapAnnuities_);
        return cmSwapAnnuities_[i]/discRatios_[numeraire];
    }

    Rate CoterminalSwapCurveState::cmSwapRate(Size i,
                                              Size spanningForwards) const {
        QL_REQUIRE(first_<nRates_, "curve state not initialized yet");
        QL_REQUIRE(i>=first_ && i<=nRates_, "invalid index");

        // consider lazy evaluation here
        constantMaturityFromDiscountRatios(spanningForwards, first_,
                                           discRatios_, taus_,
                                           cmSwapRates_, cmSwapAnnuities_);
        return cmSwapRates_[i];
    }

}
