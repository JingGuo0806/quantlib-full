
'Copyright (C) 2006, 2007 Eric Ehlers

'This file is part of QuantLib, a free-software/open-source library
'for financial quantitative analysts and developers - http://quantlib.org/

'QuantLib is free software: you can redistribute it and/or modify it
'under the terms of the QuantLib license.  You should have received a
'copy of the license along with this program; if not, please email
'<quantlib-dev@lists.sf.net>. The license is also available online at
'<http://quantlib.org/reference/license.html>.

'This program is distributed in the hope that it will be useful, but WITHOUT
'ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
'FOR A PARTICULAR PURPOSE.  See the license for more details.

Namespace QuantLibXL

    Public Class Configuration
        Implements ISerializable

        Private selectedEnvConfig_ As String = ""
        Private selectedEnvName_ As String = ""
        Private version_ As Integer
        Private overrideActions_ As QuantLibXL.StartupActionsList

        Public Property Name() As String Implements ISerializable.Name
            Get
                Name = "Configuration"
            End Get

            Set(ByVal value As String)
            End Set

        End Property

        Public Property SelectedEnvConfig() As String

            Get
                Return selectedEnvConfig_
            End Get

            Set(ByVal value As String)
                selectedEnvConfig_ = value
            End Set

        End Property

        Public Property SelectedEnvName() As String

            Get
                Return selectedEnvName_
            End Get

            Set(ByVal value As String)
                selectedEnvName_ = value
            End Set

        End Property

        Public Property OverrideActions() As QuantLibXL.StartupActionsList

            Get
                Return overrideActions_
            End Get

            Set(ByVal value As QuantLibXL.StartupActionsList)
                overrideActions_ = value
            End Set

        End Property

        Public Sub serialize(ByRef serializer As ISerializer) Implements ISerializable.serialize

            serializer.serializeProperty(selectedEnvConfig_, "SelectedEnvConfig")
            serializer.serializeProperty(selectedEnvName_, "SelectedEnvName")
            serializer.serializeProperty(version_, "Version")
            serializer.serializeObject(overrideActions_, "StartupActionsList")

        End Sub

    End Class

End Namespace
