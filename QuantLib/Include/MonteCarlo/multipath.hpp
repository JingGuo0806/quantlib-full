
/*
 * Copyright (C) 2001
 * Ferdinando Ametrano, Luigi Ballabio, Adolfo Benin, Marco Marchioro
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 *
 * QuantLib license is also available at 
 * http://quantlib.sourceforge.net/LICENSE.TXT
*/
/*! \file multipath.hpp
    \brief MultiPath implements multiple paths evolving at the same time

    $Source$
    $Name$
    $Log$
    Revision 1.2  2001/04/04 12:13:23  nando
    Headers policy part 2:
    The Include directory is added to the compiler's include search path.
    Then both your code and user code specifies the sub-directory in
    #include directives, as in
    #include <Solvers1d/newton.hpp>

    Revision 1.1  2001/04/04 11:07:22  nando
    Headers policy part 1:
    Headers should have a .hpp (lowercase) filename extension
    All *.h renamed to *.hpp

    Revision 1.1  2001/01/25 16:11:17  marmar
    MultiPath, the first step for a multi-dimensional Monte Carlo


*/
#ifndef quantlib_montecarlo_multi_path_h
#define quantlib_montecarlo_multi_path_h

#include "qldefines.hpp"
#include "Math/matrix.hpp"

namespace QuantLib {

    namespace MonteCarlo {
        
        /*!
        \brief MultiPath implements multiple paths evolving at the same time
        \typedef MultiPath
        MultiPath contains the list of variations for each asset,
        \f[
            \log \frac{Y^j_{i+1}}{Y^j_i} \mathrm{for} i = 0, \ldots, n-1
            \qquad \mathrm{and} \qquad j = 0, \ldots, m-1
        \f]
        where \f$ Y^j_i \f$ is the value of the underlying \f$ j \f$
        at discretized time \f$ t_i \f$. The first index refers to the 
        underlying, the second to the time position MultiPath[j,i]
        */
        typedef QuantLib::Math::Matrix MultiPath;
    }

}

#endif
