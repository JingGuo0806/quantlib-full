
/*
 Copyright (C) 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef quantlib_test_piecewise_flat_forward_hpp
#define quantlib_test_piecewise_flat_forward_hpp

#include <boost/test/unit_test.hpp>

/*! \class QuantLib::PiecewiseFlatForward \
    <ql/TermStructures/piecewiseflatforward.hpp>

    \test a) the correctness of the returned values is tested by
          checking them against the original inputs.

    \test b) the observability of the term structure is tested.
*/

class PiecewiseFlatForwardTest {
  public:
    static void testConsistency();
    static void testObservability();
    static boost::unit_test_framework::test_suite* suite();
};


#endif
