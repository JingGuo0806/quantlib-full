/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2003 Ferdinando Ametrano
 Copyright (C) 2001, 2002, 2003 Sadruddin Rejeb
 Copyright (C) 2004, 2005, 2006 StatPro Italia srl

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

/*! \file blackscholesprocess.hpp
    \brief Black-Scholes processes
*/

#ifndef quantlib_black_scholes_process_hpp
#define quantlib_black_scholes_process_hpp

#include <ql/stochasticprocess.hpp>
#include <ql/Processes/eulerdiscretization.hpp>
#include <ql/yieldtermstructure.hpp>
#include <ql/voltermstructure.hpp>
#include <ql/quote.hpp>

namespace QuantLib {

    //! Generalized Black-Scholes stochastic process
    /*! This class describes the stochastic process governed by
        \f[
            dS(t, S) = (r(t) - q(t) - \frac{\sigma(t, S)^2}{2}) dt
                     + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class GeneralizedBlackScholesProcess : public StochasticProcess1D {
      public:
        GeneralizedBlackScholesProcess(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& dividendTS,
            const Handle<YieldTermStructure>& riskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));
        //! \name StochasticProcess1D interface
        //@{
        Real x0() const;
        /*! \todo revise extrapolation */
        Real drift(Time t, Real x) const;
        /*! \todo revise extrapolation */
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;
        //@}
        Time time(const Date&) const;
        //! \name Observer interface
        //@{
        void update();
        //@}
        //! \name Inspectors
        //@{
        const boost::shared_ptr<Quote>& stateVariable() const;
        const boost::shared_ptr<YieldTermStructure>& dividendYield() const;
        const boost::shared_ptr<YieldTermStructure>& riskFreeRate() const;
        const boost::shared_ptr<BlackVolTermStructure>& blackVolatility()
                                                                        const;
        const boost::shared_ptr<LocalVolTermStructure>& localVolatility()
                                                                        const;
        //@}
      private:
        Handle<Quote> x0_;
        Handle<YieldTermStructure> riskFreeRate_, dividendYield_;
        Handle<BlackVolTermStructure> blackVolatility_;
        mutable Handle<LocalVolTermStructure> localVolatility_;
        mutable bool updated_;
    };

    //! Black-Scholes (1973) stochastic process
    /*! This class describes the stochastic process for a stock given by
        \f[
            dS(t, S) = (r(t) - \frac{\sigma(t, S)^2}{2}) dt + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class BlackScholes73Process : public GeneralizedBlackScholesProcess {
      public:
        BlackScholes73Process(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& riskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));
    };

    //! Merton (1973) extension to the Black-Scholes stochastic process
    /*! This class describes the stochastic process for a stock or
        stock index paying a continuous dividend yield given by
        \f[
            dS(t, S) = (r(t) - q(t) - \frac{\sigma(t, S)^2}{2}) dt
                     + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class BlackScholesMertonProcess : public GeneralizedBlackScholesProcess {
      public:
        BlackScholesMertonProcess(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& dividendTS,
            const Handle<YieldTermStructure>& riskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));
    };

    //! Black (1976) stochastic process
    /*! This class describes the stochastic process for a forward or
        futures contract given by
        \f[
            dS(t, S) = \frac{\sigma(t, S)^2}{2} dt + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class BlackProcess : public GeneralizedBlackScholesProcess {
      public:
        BlackProcess(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& riskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));
    };

    //! Garman-Kohlhagen (1983) stochastic process
    /*! This class describes the stochastic process for an exchange
        rate given by
        \f[
            dS(t, S) = (r(t) - r_f(t) - \frac{\sigma(t, S)^2}{2}) dt
                     + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class GarmanKohlagenProcess : public GeneralizedBlackScholesProcess {
      public:
        GarmanKohlagenProcess(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& foreignRiskFreeTS,
            const Handle<YieldTermStructure>& domesticRiskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));
    };

}


#endif
