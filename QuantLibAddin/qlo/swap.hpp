
/*
 Copyright (C) 2005 Eric Ehlers
 Copyright (C) 2006 Ferdinando Ametrano
 Copyright (C) 2005 Aurelien Chanudet
 Copyright (C) 2005 Plamen Neykov
 Copyright (C) 2006 Katiuscia Manzoni

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

#ifndef qla_swap_hpp
#define qla_swap_hpp

#include <qlo/baseinstruments.hpp>
#include <qlo/couponvectors.hpp>

namespace QuantLib {
    class CmsCouponPricer;
}

namespace QuantLibAddin {
    
    class Swap : public Instrument {
      public:
        Swap(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
             const std::vector<boost::shared_ptr<Leg> >& legWrappers,
             const std::vector<bool>& payer,
             const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
             bool permanent);
        // MakeCms
        Swap(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
             const QuantLib::Period& swapTenor,
             const boost::shared_ptr<QuantLib::SwapIndex>& swapIndex,
             const QuantLib::Spread iborSpread,
             const boost::shared_ptr<QuantLib::CmsCouponPricer>& pricer,
             const QuantLib::Period& forwardStart,
             bool permanent);

        std::vector<std::vector<boost::any> > legAnalysis(QuantLib::Size i);

      protected:
        OH_OBJ_CTOR(Swap, Instrument);
    };
    
}

#endif
