/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2003 Ferdinando Ametrano
 Copyright (C) 2006 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file brownianbridge.hpp
    \brief Browian bridge
*/

// ===========================================================================
// NOTE: The following copyright notice applies to the original code,
//
// Copyright (C) 2002 Peter J�ckel "Monte Carlo Methods in Finance".
// All rights reserved.
//
// Permission to use, copy, modify, and distribute this software is freely
// granted, provided that this notice is preserved.
// ===========================================================================

#ifndef quantlib_brownian_bridge_hpp
#define quantlib_brownian_bridge_hpp

#include <ql/methods/montecarlo/path.hpp>
#include <ql/methods/montecarlo/sample.hpp>
#include <ql/voltermstructures/equityfx/blackvoltermstructure.hpp>

namespace QuantLib {

    //! Builds Wiener process paths using Gaussian variates
    /*! This class generates normalized (i.e., unit-variance) paths as
        sequences of variations. In order to obtain the actual path of
        the underlying, the returned variations must be multiplied by
        the integrated variance (including time) over the
        corresponding time step.

        \ingroup mcarlo
    */
    class BrownianBridge {
      public:
        //! unit-time path
        BrownianBridge(Size steps);
        //! generic times
        /*! \note the starting time of the path is assumed to be 0
                  and must not be included
        */
        BrownianBridge(const std::vector<Time>& times);
        //! generic times
        BrownianBridge(const TimeGrid& timeGrid);
        //! \name inspectors
        //@{
        Size size() const;
        const std::vector<Time>& times() const;
        //@}
        //! \name Brownian-bridge constructor
        //@{
        template <class RandomAccessIterator1,
                  class RandomAccessIterator2>
        void transform(RandomAccessIterator1 begin,
                       RandomAccessIterator1 end,
                       RandomAccessIterator2 output) const {
            QL_REQUIRE(end >= begin, "invalid sequence");
            QL_REQUIRE(Size(end-begin) == size_,
                       "incompatible sequence size");
            // We use output to store the path...
            output[size_-1] = stdDev_[0] * begin[0];
            for (Size i=1; i<size_; ++i) {
                Size j = leftIndex_[i];
                Size k = rightIndex_[i];
                Size l = bridgeIndex_[i];
                if (j != 0) {
                    output[l] =
                        leftWeight_[i] * output[j-1] +
                        rightWeight_[i] * output[k]   +
                        stdDev_[i] * begin[i];
                } else {
                    output[l] =
                        rightWeight_[i] * output[k]   +
                        stdDev_[i] * begin[i];
                }
            }
            // ...after which, we calculate the variations and
            // normalize to unit times
            for (Size i=size_-1; i>=1; --i) {
                output[i] -= output[i-1];
                output[i] /= sqrtdt_[i];
            }
            output[0] /= sqrtdt_[0];
        }
      private:
        void initialize();
        Size size_;
        std::vector<Time> t_;
        std::vector<Real> sqrtdt_;
        std::vector<Size> bridgeIndex_, leftIndex_, rightIndex_;
        std::vector<Real> leftWeight_, rightWeight_, stdDev_;
    };

    inline Size BrownianBridge::size() const {
        return size_;
    }

    inline const std::vector<Time>& BrownianBridge::times() const {
        return t_;
    }

}


#endif
