# Microsoft Developer Studio Project File - Name="QuantLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=QuantLib - Win32 OnTheEdgeDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "QuantLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QuantLib.mak" CFG="QuantLib - Win32 OnTheEdgeDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QuantLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "QuantLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "QuantLib - Win32 OnTheEdgeRelease" (based on "Win32 (x86) Static Library")
!MESSAGE "QuantLib - Win32 OnTheEdgeDebug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QuantLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "build\Release"
# PROP Intermediate_Dir "build\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /Gi /GR /GX /Od /Ob2 /I ".\\" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "NOMINMAX" /FR /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib.lib"

!ELSEIF  "$(CFG)" == "QuantLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "build\Debug"
# PROP Intermediate_Dir "build\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gi /GR /GX /ZI /Od /I ".\\" /D "_DEBUG" /D "QL_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "NOMINMAX" /FR /YX /Fd"lib\Win32\VisualStudio\QuantLib" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib_d.lib"

!ELSEIF  "$(CFG)" == "QuantLib - Win32 OnTheEdgeRelease"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuantLib___Win32_OnTheEdgeRelease0"
# PROP BASE Intermediate_Dir "QuantLib___Win32_OnTheEdgeRelease0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "build\OnTheEdgeRelease"
# PROP Intermediate_Dir "build\OnTheEdgeRelease"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /Od /Ob2 /I "Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /c
# ADD CPP /nologo /MD /W3 /Gi /GR /GX /Od /Ob2 /I ".\\" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "NOMINMAX" /FR /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib.lib"
# ADD LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib.lib"

!ELSEIF  "$(CFG)" == "QuantLib - Win32 OnTheEdgeDebug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuantLib___Win32_OnTheEdgeDebug0"
# PROP BASE Intermediate_Dir "QuantLib___Win32_OnTheEdgeDebug0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "build\OnTheEdgeDebug"
# PROP Intermediate_Dir "build\OnTheEdgeDebug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /GR /GX /ZI /Od /I "Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "QL_DEBUG" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gi /GR /GX /ZI /Od /I ".\\" /D "_DEBUG" /D "QL_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "NOMINMAX" /FR /YX /Fd"lib\Win32\VisualStudio\QuantLib" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib_d.lib"
# ADD LIB32 /nologo /out:"lib\Win32\VisualStudio\QuantLib_d.lib"

!ENDIF 

# Begin Target

# Name "QuantLib - Win32 Release"
# Name "QuantLib - Win32 Debug"
# Name "QuantLib - Win32 OnTheEdgeRelease"
# Name "QuantLib - Win32 OnTheEdgeDebug"
# Begin Group "Calendars"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Calendars\frankfurt.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\frankfurt.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\helsinki.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\helsinki.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\johannesburg.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\johannesburg.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\london.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\london.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\milan.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\milan.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\newyork.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\newyork.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\sydney.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\sydney.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\target.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\target.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\tokyo.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\tokyo.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\toronto.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\toronto.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\wellington.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\wellington.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\zurich.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Calendars\zurich.hpp
# End Source File
# End Group
# Begin Group "CashFlows"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\CashFlows\cashflowvectors.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\cashflowvectors.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\fixedratecoupon.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\floatingratecoupon.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\floatingratecoupon.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\shortfloatingcoupon.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\shortfloatingcoupon.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\CashFlows\simplecashflow.hpp
# End Source File
# End Group
# Begin Group "Day Counters"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\DayCounters\actual360.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\DayCounters\actual365.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\DayCounters\actualactual.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\DayCounters\actualactual.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\DayCounters\thirty360.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\DayCounters\thirty360.hpp
# End Source File
# End Group
# Begin Group "Finite Differences"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\FiniteDifferences\americancondition.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\boundarycondition.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\bsmoperator.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\bsmoperator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\cranknicolson.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\dminus.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\dplus.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\dplusdminus.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\dzero.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\expliciteuler.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\fdtypedefs.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\finitedifferencemodel.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\impliciteuler.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\mixedscheme.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\onefactoroperator.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\onefactoroperator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\shoutcondition.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\stepcondition.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\tridiagonaloperator.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\tridiagonaloperator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\valueatcenter.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\FiniteDifferences\valueatcenter.hpp
# End Source File
# End Group
# Begin Group "Indexes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Indexes\audlibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\cadlibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\chflibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\euribor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\gbplibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\jpylibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\usdlibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\xibor.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\xibor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\xibormanager.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\xibormanager.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Indexes\zarlibor.hpp
# End Source File
# End Group
# Begin Group "Instruments"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Instruments\capfloor.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\capfloor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\plainoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\plainoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\simpleswap.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\simpleswap.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\stock.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\stock.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\swap.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\swap.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\swaption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Instruments\swaption.hpp
# End Source File
# End Group
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Math\cubicspline.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\interpolation.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\lexicographicalview.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\linearinterpolation.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\matrix.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\matrix.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\multivariateaccumulator.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\multivariateaccumulator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\normaldistribution.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\normaldistribution.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\riskmeasures.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\segmentintegral.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\segmentintegral.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\statistics.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\statistics.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\symmetriceigenvalues.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\symmetricschurdecomposition.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Math\symmetricschurdecomposition.hpp
# End Source File
# End Group
# Begin Group "MonteCarlo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\MonteCarlo\arithmeticapopathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\arithmeticapopathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\arithmeticasopathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\arithmeticasopathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\basketpathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\basketpathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\europeanpathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\europeanpathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\everestpathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\everestpathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\geometricapopathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\geometricapopathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\geometricasopathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\geometricasopathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\getcovariance.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\getcovariance.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\himalayapathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\himalayapathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\maxbasketpathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\maxbasketpathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\mctypedefs.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\montecarlomodel.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\multipath.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\multipathgenerator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\pagodapathpricer.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\pagodapathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\path.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\pathgenerator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\pathpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\MonteCarlo\sample.hpp
# End Source File
# End Group
# Begin Group "Patterns"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Patterns\observable.hpp
# End Source File
# End Group
# Begin Group "Pricers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Pricers\analyticalcapfloor.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\analyticalcapfloor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\barrieroption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\barrieroption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\binaryoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\binaryoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\cliquetoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\cliquetoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\continuousgeometricapo.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\discretegeometricapo.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\discretegeometricapo.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\discretegeometricaso.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\discretegeometricaso.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\europeanengine.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\europeanengine.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\europeanoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\europeanoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdamericanoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdbermudanoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdbermudanoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdbsmoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdbsmoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendamericanoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendamericanoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendeuropeanoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendeuropeanoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendshoutoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fddividendshoutoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdeuropean.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdeuropean.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdmultiperiodoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdmultiperiodoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdshoutoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdstepconditionoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\fdstepconditionoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\jamshidianswaption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\jamshidianswaption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcbasket.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcbasket.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcdiscretearithmeticapo.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcdiscretearithmeticapo.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcdiscretearithmeticaso.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcdiscretearithmeticaso.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mceuropean.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mceuropean.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mceverest.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mceverest.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mchimalaya.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mchimalaya.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcmaxbasket.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcmaxbasket.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcpagoda.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcpagoda.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\mcpricer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\singleassetoption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\singleassetoption.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\treecapfloor.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\treecapfloor.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\treeswaption.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Pricers\treeswaption.hpp
# End Source File
# End Group
# Begin Group "RandomNumbers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\RandomNumbers\boxmullergaussianrng.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\centrallimitgaussianrng.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\inversecumgaussianrng.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\knuthuniformrng.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\knuthuniformrng.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\lecuyeruniformrng.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\lecuyeruniformrng.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\randomarraygenerator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\RandomNumbers\rngtypedefs.hpp
# End Source File
# End Group
# Begin Group "Solvers 1D"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Solvers1D\bisection.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\bisection.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\brent.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\brent.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\falseposition.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\falseposition.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\newton.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\newton.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\newtonsafe.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\newtonsafe.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\ridder.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\ridder.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\secant.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Solvers1D\secant.hpp
# End Source File
# End Group
# Begin Group "Term Structures"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\TermStructures\flatforward.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\TermStructures\piecewiseflatforward.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\TermStructures\piecewiseflatforward.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\TermStructures\ratehelpers.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\TermStructures\ratehelpers.hpp
# End Source File
# End Group
# Begin Group "Utilities"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Utilities\combiningiterator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Utilities\couplingiterator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Utilities\filteringiterator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Utilities\iteratorcategories.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Utilities\processingiterator.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Utilities\steppingiterator.hpp
# End Source File
# End Group
# Begin Group "InterestRateModellling"

# PROP Default_Filter ""
# Begin Group "OneFactorModels"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\blackkarasinski.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\blackkarasinski.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\coxingersollross.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\coxingersollross.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\hullwhite.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\OneFactorModels\hullwhite.hpp
# End Source File
# End Group
# Begin Group "CalibrationHelpers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\InterestRateModelling\CalibrationHelpers\caphelper.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\CalibrationHelpers\caphelper.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\CalibrationHelpers\swaptionhelper.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\CalibrationHelpers\swaptionhelper.hpp
# End Source File
# End Group
# Begin Group "TwoFactorModels"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\InterestRateModelling\TwoFactorModels\g2.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\TwoFactorModels\g2.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ql\InterestRateModelling\calibrationhelper.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\calibrationhelper.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\model.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\model.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\onefactormodel.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\onefactormodel.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\parameter.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\shortrateprocess.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\InterestRateModelling\twofactormodel.hpp
# End Source File
# End Group
# Begin Group "Optimization"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Optimization\armijo.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\armijo.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\conjugategradient.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\conjugategradient.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\constraint.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\costfunction.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\criteria.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\leastsquare.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\linesearch.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\optimizer.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\powell.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\powell.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\simplex.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\simplex.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\simulatedannealing.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\simulatedannealing.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\steepestdescent.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Optimization\steepestdescent.hpp
# End Source File
# End Group
# Begin Group "Lattices"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\Lattices\binomialtree.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\binomialtree.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\node.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\tree.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\tree.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\trinomialtree.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\Lattices\trinomialtree.hpp
# End Source File
# End Group
# Begin Group "functions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ql\functions\daycounters.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\functions\daycounters.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ql\argsandresults.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\array.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\asset.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\calendar.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\calendar.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\cashflow.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\config.ansi.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\config.bcc.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\config.decc.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\config.msvc.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\config.mwcw.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\currency.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\dataformatters.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\dataformatters.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\date.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\date.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\daycounter.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\diffusionprocess.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\errors.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\exercise.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\expressiontemplates.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\forwardvolsurface.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\handle.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\history.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\index.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\instrument.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\marketelement.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\null.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\option.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\option.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\qldefines.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\quantlib.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\relinkablehandle.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\riskstatistics.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\scheduler.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\scheduler.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\solver1d.cpp
# End Source File
# Begin Source File

SOURCE=.\ql\solver1d.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\swaptionvolsurface.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\termstructure.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\timegrid.hpp
# End Source File
# Begin Source File

SOURCE=.\ql\types.hpp
# End Source File
# End Target
# End Project
