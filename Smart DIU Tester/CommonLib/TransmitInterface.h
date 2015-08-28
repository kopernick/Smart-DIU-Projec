#pragma once

using namespace System;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Collections::Generic;

namespace PMCommunication {

	public enum class CommunicationRedundant
	{
		None,
		Primary,
		Secondary
	};

	public enum class CommunicationType {
		None,
		SerialPort,
		TCP
	};

	public ref class TransmitEventArgs : public EventArgs
	{
	public:
		array<Byte>^ m_lpDataArray;
		int m_nLength;

	public:
		TransmitEventArgs()
		{
		  this->m_lpDataArray = nullptr;
		}

		TransmitEventArgs(array<Byte>^ lpDataArray, int nLength)
		{
		  this->m_lpDataArray = lpDataArray;
		  this->m_nLength = nLength;
		}
	};

	public ref class CTransmitInterface abstract
	{
	protected:
		// Thread Worker
		Thread^ m_TxThread;
		Thread^ m_RxThread;
		bool m_bCloseRequested;

	public:
		CommunicationType m_CommunicationType;

		// Statistics
		UInt32 m_nTxTotals;
		UInt32 m_nRxTotals;
		UInt32 m_nErrorTotals;

		UInt32 m_nPreConditionTime;
		UInt32 m_nPostConditionTime;

		String^ m_strErrorMessage;

		AutoResetEvent^ m_hTransmitEvent;

	public:
		delegate void TransmitEventHandler(Object^ sender, TransmitEventArgs^ e);

		// Event Handler
		event TransmitEventHandler^ OnConnected;
		event TransmitEventHandler^ OnDisconnected;
		event TransmitEventHandler^ OnDataReceived;
		event TransmitEventHandler^ OnDataSent;
		event TransmitEventHandler^ OnErrorReceived;

	public:
		property CommunicationType TheCommunicationType
		{
			CommunicationType get() 
			{ 
				return this->m_CommunicationType; 
			}

			void set(CommunicationType value) 
			{
				this->m_CommunicationType = value; 
			}
		}

		property UInt32 PreConditionTime
		{
			UInt32 get() 
			{ 
				return this->m_nPreConditionTime; 
			}

			void set(UInt32 value) 
			{
				this->m_nPreConditionTime = value; 
			}
		}

		property UInt32 PostConditionTime
		{
			UInt32 get() 
			{ 
				return this->m_nPostConditionTime; 
			}

			void set(UInt32 value) 
			{
				this->m_nPostConditionTime = value; 
			}
		}

		property String^ ErrorMessage
		{
			String^ get() { return this->m_strErrorMessage; }
			void set(String^ value) { this->m_strErrorMessage = value; }
		}

	public:
		CTransmitInterface(void);
		~CTransmitInterface(void);
		!CTransmitInterface(void);

	protected:
		virtual void RxDataThreadOperation();
		virtual void TxDataThreadOperation();

	// Implements
	public:
		virtual void Connect(void) abstract;
		virtual void Disconnect(void) abstract;		
		virtual bool IsConnected() abstract;
		virtual UInt64 Transmit(array<Byte>^ lpDataOut) abstract;

		virtual void vLoadConfiguration(System::IO::BinaryReader ^lpReader) abstract;
		virtual void vSaveConfiguration(System::IO::BinaryWriter ^lpWriter) abstract;
	};
}
