/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Mark Joshi

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


#ifndef quantlib_piecewise_const_variance_hpp
#define quantlib_piecewise_const_variance_hpp

#include <ql/types.hpp>
#include <vector>

namespace QuantLib {

    class EvolutionDescription;
    class Matrix;

    class PiecewiseConstantVariance {
      public:
        virtual ~PiecewiseConstantVariance() {}
        virtual const EvolutionDescription& evolution() const = 0;
        virtual const std::vector<Real>& variances() const = 0;
    };

}

#endif
