
/*
 Copyright (C) 2002, 2003 Ferdinando Ametrano

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

/*! \file forwardengines.hpp
    \brief Forward (strike-resetting) option engines
*/

#ifndef quantlib_forward_engines_h
#define quantlib_forward_engines_h

#include <ql/Instruments/forwardvanillaoption.hpp>
#include <ql/Volatilities/impliedvoltermstructure.hpp>
#include <ql/TermStructures/impliedtermstructure.hpp>

namespace QuantLib {

    //! Forward engine base class
    template<class ArgumentsType, class ResultsType>
    class ForwardEngine
        : public GenericEngine<ForwardOptionArguments<ArgumentsType>,
                               ResultsType> {
      public:
        ForwardEngine(const Handle<GenericEngine<ArgumentsType,
                                                 ResultsType> >&);
        void setOriginalArguments() const;
        void calculate() const;
        void getOriginalResults() const;
      protected:
        Handle<GenericEngine<ArgumentsType, ResultsType> > originalEngine_;
        ArgumentsType* originalArguments_;
        const ResultsType* originalResults_;
    };

    template<class ArgumentsType, class ResultsType>
    ForwardEngine<ArgumentsType, ResultsType>::ForwardEngine(
        const Handle<GenericEngine<ArgumentsType, ResultsType> >&
            originalEngine)
    : originalEngine_(originalEngine) {
        QL_REQUIRE(!IsNull(originalEngine_),
                   "ForwardEngine::ForwardEngine: null engine");
        originalResults_ = dynamic_cast<const ResultsType*>(
            originalEngine_->results());
        originalArguments_ = dynamic_cast<ArgumentsType*>(
            originalEngine_->arguments());
    }


    template<class ArgumentsType, class ResultsType>
    void ForwardEngine<ArgumentsType, ResultsType>::setOriginalArguments()
                                                                        const {


/*
        #if defined(HAVE_BOOST)
        Handle<TypePayoff> argumentsPayoff =
            boost::dynamic_pointer_cast<TypePayoff>(arguments_.payoff);
        QL_REQUIRE(argumentsPayoff,
                   "ForwardEngine: wrong payoff given");
        #else
        Handle<TypePayoff> argumentsPayoff = arguments_.payoff;
        #endif

        originalArguments_->payoff = Handle<StrikedTypePayoff>(
            new StrikedTypePayoff(
                argumentsPayoff->optionType(),
                arguments_.moneyness * arguments_.blackScholesProcess->stateVariable->value()));
*/

        #if defined(HAVE_BOOST)
        Handle<StrikedTypePayoff> argumentsPayoff =
            boost::dynamic_pointer_cast<StrikedTypePayoff>(arguments_.payoff);
        QL_REQUIRE(argumentsPayoff,
                   "ForwardEngine: wrong payoff given");
        #else
        Handle<StrikedTypePayoff> argumentsPayoff = arguments_.payoff;
        #endif

        argumentsPayoff->setStrike(arguments_.moneyness*
            arguments_.blackScholesProcess->stateVariable->value());
        originalArguments_->payoff = argumentsPayoff;


        // maybe the forward value is "better", in some fashion
        // the right level is needed in order to interpolate
        // the vol
        originalArguments_->blackScholesProcess->stateVariable = arguments_.blackScholesProcess->stateVariable;
        originalArguments_->blackScholesProcess->dividendTS = RelinkableHandle<TermStructure>(
            Handle<TermStructure>(new
                ImpliedTermStructure(
                        arguments_.blackScholesProcess->dividendTS, arguments_.resetDate,
                        arguments_.resetDate)));
        originalArguments_->blackScholesProcess->riskFreeTS = RelinkableHandle<TermStructure>(
            Handle<TermStructure>(new
                ImpliedTermStructure(
                        arguments_.blackScholesProcess->riskFreeTS, arguments_.resetDate,
                        arguments_.resetDate)));

        // The following approach is ok if the vol is at most
        // time dependant. It is plain wrong if it is asset dependant.
        // In the latter case the right solution would be stochastic
        // volatility or at least local volatility (which unfortunately
        // implies an unrealistic time-decreasing smile)
        originalArguments_->blackScholesProcess->volTS =
            RelinkableHandle<BlackVolTermStructure>(
                Handle<BlackVolTermStructure>(new
                    ImpliedVolTermStructure(arguments_.blackScholesProcess->volTS,
                                            arguments_.resetDate)));

        originalArguments_->exercise  = arguments_.exercise;

        originalArguments_->validate();
    }



    template<class ArgumentsType, class ResultsType>
    void ForwardEngine<ArgumentsType, ResultsType>::calculate() const {
        originalEngine_->reset();
        setOriginalArguments();
        originalEngine_->calculate();
        getOriginalResults();
    }

    template<class ArgumentsType, class ResultsType>
    void ForwardEngine<ArgumentsType, ResultsType>::getOriginalResults()
                                                                      const {

        Time resetTime = arguments_.blackScholesProcess->riskFreeTS->dayCounter().yearFraction(
                arguments_.blackScholesProcess->riskFreeTS->referenceDate(), arguments_.resetDate);
        double discQ = arguments_.blackScholesProcess->dividendTS->discount(arguments_.resetDate);

        results_.value = discQ * originalResults_->value;
        // I need the strike derivative here ...
        results_.delta = discQ * (originalResults_->delta +
                  arguments_.moneyness * originalResults_->strikeSensitivity);
        results_.gamma = 0.0;
        results_.theta = arguments_.blackScholesProcess->dividendTS->zeroYield(
                                       arguments_.resetDate) * results_.value;
        results_.vega  = discQ * originalResults_->vega;
        results_.rho   = discQ *  originalResults_->rho;
        results_.dividendRho = - resetTime * results_.value
            + discQ * originalResults_->dividendRho;

    }




    //! Forward Performance engine base class
    template<class ArgumentsType, class ResultsType>
    class ForwardPerformanceEngine
        : public ForwardEngine<ArgumentsType, ResultsType> {
      public:
        ForwardPerformanceEngine(
                    const Handle<GenericEngine<ArgumentsType,ResultsType> >&);
        void calculate() const;
        void getOriginalResults() const;
    };

    template<class ArgumentsType, class ResultsType>
    ForwardPerformanceEngine<ArgumentsType, ResultsType>::ForwardPerformanceEngine(
        const Handle<GenericEngine<ArgumentsType, ResultsType> >&
            originalEngine)
    : ForwardEngine<ArgumentsType, ResultsType>(originalEngine) {}

    template<class ArgumentsType, class ResultsType>
    void ForwardPerformanceEngine<ArgumentsType, ResultsType>::calculate() const {

        setOriginalArguments();
        originalEngine_->calculate();
        getOriginalResults();
    }

    template<class ArgumentsType, class ResultsType>
    void ForwardPerformanceEngine<ArgumentsType, ResultsType>::getOriginalResults() const {

        Time resetTime = arguments_.blackScholesProcess->riskFreeTS->dayCounter().yearFraction(
                arguments_.blackScholesProcess->riskFreeTS->referenceDate(), arguments_.resetDate);
        double discR = arguments_.blackScholesProcess->riskFreeTS->discount(arguments_.resetDate);
        // it's a performance option
        discR /= arguments_.blackScholesProcess->stateVariable->value();

        double temp = originalResults_->value;
        results_.value = discR * temp;
        results_.delta = 0.0;
        results_.gamma = 0.0;
        results_.theta = arguments_.blackScholesProcess->riskFreeTS->zeroYield(
                arguments_.resetDate) * results_.value;
        results_.vega = discR * originalResults_->vega;
        results_.rho = - resetTime * results_.value +
            discR * originalResults_->rho;
        results_.dividendRho = discR * originalResults_->dividendRho;

    }

}


#endif
