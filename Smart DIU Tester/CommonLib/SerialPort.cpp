#include "StdAfx.h"
#include "TransmitInterface.h"
#include "SerialPort.h"

PMCommunication::CSerialPort::CSerialPort()
{
	this->TheCommunicationType = CommunicationType::SerialPort;

	this->m_SerialPort = gcnew SerialPort();
	this->ReadBufferSize = 4 * 1024;
	this->WriteBufferSize = 4 * 1024;
	this->m_arrayRecvBuffer = gcnew array<Byte>(4*1024);
	this->m_SerialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &CSerialPort::OnSerialPortDataReceived);
	this->m_nPreConditionTime = 100;
	this->m_nPostConditionTime = 100;
}

PMCommunication::CSerialPort::~CSerialPort()
{
	Disconnect();
	delete this->m_SerialPort;
	delete this->m_arrayRecvBuffer;
}

PMCommunication::CSerialPort::!CSerialPort()
{
	this->~CSerialPort();
}

void PMCommunication::CSerialPort::Connect(String^ strPortName, int iBaudRate, System::IO::Ports::Parity parity, int iDataBit)
{
	if (this->m_SerialPort->IsOpen) return;
	this->PortName = strPortName;
	this->BaudRate = iBaudRate;
	this->Parity = parity;
	this->DataBits = iDataBit;
	this->Connect();
}

void PMCommunication::CSerialPort::Connect()
{
	try {
		if (this->m_SerialPort->IsOpen) return;
		this->m_SerialPort->Open();
		this->OnConnected(this, gcnew TransmitEventArgs());
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CSerialPort::Connect : {0} Connect Failure -> {1}", this->PortName, e->Message));
	}
}

void PMCommunication::CSerialPort::Disconnect(void)
{
	try {
		if (this->m_SerialPort->IsOpen) {
			this->m_SerialPort->Close();
		}
		this->m_nRxTotals = 0;
		this->m_nTxTotals = 0;
		this->OnDisconnected(this, gcnew TransmitEventArgs());
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CSerialPort::Disconnect : {0}", e->Message));
	}
}

void PMCommunication::CSerialPort::OnSerialPortDataReceived(Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
{
	try {
		if (this->m_SerialPort->BytesToRead > 0) {
			int iBytesRead = this->m_SerialPort->Read(this->m_arrayRecvBuffer, 0, this->m_arrayRecvBuffer->Length);
			this->OnDataReceived(this, gcnew TransmitEventArgs(this->m_arrayRecvBuffer, iBytesRead));
			this->m_nRxTotals += iBytesRead;
		}
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CSerialPort::OnSerialPortDataReceived : {0}", e->Message));
	}
}

UInt64 PMCommunication::CSerialPort::Transmit(array<Byte> ^lpBufOut)
{
	try {
		this->m_SerialPort->RtsEnable = true;
		this->m_SerialPort->Write(lpBufOut, 0, lpBufOut->Length);	
		this->OnDataSent(this, gcnew TransmitEventArgs(lpBufOut, lpBufOut->Length));
		this->m_SerialPort->RtsEnable = false;
		this->m_nTxTotals += lpBufOut->Length;
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CSerialPort::Transmit : {0}", e->Message));
	}

	return 0;
}
void PMCommunication::CSerialPort::Transmit(String^ cmdArduino)
{
	try {
		this->m_SerialPort->RtsEnable = true;
		this->m_SerialPort->Write(cmdArduino);
		//this->OnDataSent(this, gcnew TransmitEventArgs(lpBufOut, lpBufOut->Length));
		//this->m_SerialPort->RtsEnable = false;
		//this->m_nTxTotals += lpBufOut->Length;
	}
	catch (Exception ^e) {
		System::Diagnostics::Debug::WriteLine(String::Format("CSerialPort::Transmit : {0}", e->Message));
	}
}

void PMCommunication::CSerialPort::vLoadConfiguration(System::IO::BinaryReader ^lpReader)
{
	this->PortName = lpReader->ReadString();
	this->BaudRate = lpReader->ReadInt32();
	this->DataBits = lpReader->ReadInt32();
	this->Parity = (System::IO::Ports::Parity) lpReader->ReadInt32();
	this->StopBits = (System::IO::Ports::StopBits) lpReader->ReadInt32();
	this->ReadBufferSize = lpReader->ReadInt32();
	this->WriteBufferSize = lpReader->ReadInt32();
	this->PreConditionTime = lpReader->ReadInt32();
	this->PostConditionTime = lpReader->ReadInt32();
}

void PMCommunication::CSerialPort::vSaveConfiguration(System::IO::BinaryWriter ^lpWriter)
{
	lpWriter->Write(this->PortName);
	lpWriter->Write(this->BaudRate);
	lpWriter->Write(this->DataBits);
	lpWriter->Write((int) this->Parity);
	lpWriter->Write((int) this->StopBits);
	lpWriter->Write(this->ReadBufferSize);
	lpWriter->Write(this->WriteBufferSize);
	lpWriter->Write(this->PreConditionTime);
	lpWriter->Write(this->PostConditionTime);
}
