
/*  
 Copyright (C) 2007, 2008 Eric Ehlers
 
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

#include <Addins/Cpp/init.hpp>
#include <oh/repository.hpp>
#include <oh/Enumerations/enumregistry.hpp>
#include <qlo/Enumerations/Register/register_all.hpp>
#include <qlo/Serialization/serializationfactory.hpp>

void QuantLibAddinCpp::initializeAddin() {

        // Instantiate the ObjectHandler Repository
        static ObjectHandler::Repository repository;

        // Instantiate the Serialization Factory
        static QuantLibAddin::SerializationFactory factory;

        // Instantiate the Enumerated Type Registry
        static ObjectHandler::EnumTypeRegistry enumTypeRegistry;

        // Instantiate the Enumerated Class Registry
        static ObjectHandler::EnumClassRegistry enumClassRegistry;

        // Instantiate the Enumerated Pair Registry
        static ObjectHandler::EnumPairRegistry enumPairRegistry;

        // Initialize the Enumeration Registry
        QuantLibAddin::registerEnumerations();

}

