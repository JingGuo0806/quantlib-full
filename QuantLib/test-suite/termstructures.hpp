
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

#ifndef quantlib_test_term_structures_hpp
#define quantlib_test_term_structures_hpp

#include <boost/test/unit_test.hpp>

/*! \class QuantLib::ImpliedTermStructure \
    <ql/TermStructures/impliedtermstructure.hpp>

    \test a) the correctness of the returned values is tested by
          checking them against numerical calculations.

    \test b) observability of the term structure is checked.
*/

/*! \class QuantLib::ForwardSpreadedTermStructure \
    <ql/TermStructures/forwardspreadedtermstructure.hpp>

    \test a) the correctness of the returned values is tested by
          checking them against numerical calculations.

    \test b) observability of the term structure is checked.
*/

/*! \class QuantLib::ZeroSpreadedTermStructure \
    <ql/TermStructures/zerospreadedtermstructure.hpp>

    \test a) the correctness of the returned values is tested by
          checking them against numerical calculations.

    \test b) observability of the term structure is checked.
*/

class TermStructureTest {
  public:
    static void testImplied();
    static void testImpliedObs();
    static void testFSpreaded();
    static void testFSpreadedObs();
    static void testZSpreaded();
    static void testZSpreadedObs();
    static boost::unit_test_framework::test_suite* suite();
};


#endif
