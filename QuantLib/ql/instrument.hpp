

/*
 Copyright (C) 2000, 2001, 2002 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
/*! \file instrument.hpp
    \brief Abstract instrument class

    \fullpath
    ql/%instrument.hpp
*/

// $Id$

#ifndef quantlib_instrument_h
#define quantlib_instrument_h

#include <ql/Patterns/observable.hpp>

/*! \namespace QuantLib::Instruments
    \brief Concrete implementations of the Instrument interface

    See sect. \ref instruments
*/

namespace QuantLib {

    //! Abstract instrument class
    /*! This class is purely abstract and defines the interface of concrete
        instruments which will be derived from this one.
    */
    class Instrument : public Patterns::Observer,
                       public Patterns::Observable {
      public:
        Instrument(const std::string& isinCode = "",
            const std::string& description = "");
        virtual ~Instrument() {}

        //! \name Inspectors
        //@{
        //! returns the ISIN code of the instrument, when given.
        std::string isinCode() const;
        //! returns a brief textual description of the instrument.
        std::string description() const;
        //! returns the net present value of the instrument.
        double NPV() const;
        //! returns whether the instrument is still tradable.
        bool isExpired() const;
        //@}

        //! \name Observer interface
        //@{
        void update();
        //@}

        /*! \name Calculations
            These methods do not modify the structure of the instrument and
            are therefore declared as <tt>const</tt>. Temporary variables
            will be declared as mutable.
        */
        //@{
        /*! This method force the recalculation of the instrument value and
            other results which would otherwise be cached. It is not
            declared as const since it needs to call the non-const
            <i><b>notifyObservers</b></i> method.
            \note Explicit invocation of this method is <b>not</b>
            necessary if the instrument registered itself as observer
            with the structures on which such results depend.
            It is strongly advised to follow this policy when possible.
        */
        void recalculate();
      protected:
        /*! This method performs all needed calculations by calling
            the <i><b>performCalculations</b></i> method.

            \warning Instruments cache the results of the previous
            calculation. Such results will be returned upon later
            invocations of <i><b>calculate</b></i>. When the results depend
            on arguments such as term structures which could change
            between invocations, the instrument must register itself as
            observer of such objects for the calculations to be performed
            again when they change.

            \warning This method should <b>not</b> be redefined in derived
            classes.
        */
        void calculate() const;
        /*! This method must implement any calculations which must be
            (re)done in order to calculate the NPV of the instrument.
        */
        virtual void performCalculations() const = 0;
        //@}

        /*! \name Results
            The value of these attributes must be set in the body of the
            <b>performCalculations</b> method.
        */
        //@{
        mutable double NPV_;
        mutable bool isExpired_;
        //@}
      private:
        std::string isinCode_, description_;
        mutable bool calculated;

    };

    // inline definitions

    inline Instrument::Instrument(const std::string& isinCode,
        const std::string& description)
        : NPV_(0.0),
        isExpired_(false),
        isinCode_(isinCode),
        description_(description),
        calculated(false) {}

    inline std::string Instrument::isinCode() const {
        return isinCode_;
    }

    inline std::string Instrument::description() const {
        return description_;
    }

    inline double Instrument::NPV() const {
        calculate();
        return (isExpired_ ? 0.0 : NPV_);
    }

    inline bool Instrument::isExpired() const {
        calculate();
        return isExpired_;
    }

    inline void Instrument::update() {
        calculated = false;
        notifyObservers();
    }

    inline void Instrument::recalculate() {
        performCalculations();
        calculated = true;
        notifyObservers();
    }

    inline void Instrument::calculate() const {
        if (!calculated)
            performCalculations();
        calculated = true;
    }

}


#endif
