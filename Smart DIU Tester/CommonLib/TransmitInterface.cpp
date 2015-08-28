#include "StdAfx.h"
#include "TransmitInterface.h"

PMCommunication::CTransmitInterface::CTransmitInterface(void)
{
	this->m_nRxTotals = 0;
	this->m_nTxTotals = 0;
	this->m_bCloseRequested = false;
	this->m_hTransmitEvent = gcnew AutoResetEvent(true);

	this->m_TxThread = nullptr;
	this->m_RxThread = nullptr;
}

PMCommunication::CTransmitInterface::~CTransmitInterface(void)
{
	this->m_bCloseRequested = true;
	if (this->m_hTransmitEvent) this->m_hTransmitEvent->Close();

	this->m_TxThread = nullptr;
	this->m_RxThread = nullptr;
}

PMCommunication::CTransmitInterface::!CTransmitInterface(void)
{
	this->~CTransmitInterface();
}

void PMCommunication::CTransmitInterface::RxDataThreadOperation(void)
{
	try {
		while (!this->m_bCloseRequested) {
			Thread::Sleep(5000);
		}
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CTransmitInterface::RxDataThreadOperation : {0}", e->Message));
	}
	System::Diagnostics::Debug::WriteLine("Rx Data Thread Stopped");
}

void PMCommunication::CTransmitInterface::TxDataThreadOperation(void)
{
	try {
		while (!this->m_bCloseRequested) {
			Thread::Sleep(5000);
		}
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CTransmitInterface::TxDataThreadOperation : {0}", e->Message));
	}
	System::Diagnostics::Debug::WriteLine("Tx Data Thread Stopped");
}
