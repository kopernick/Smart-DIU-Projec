#pragma once

#include "Bytes.h"
#include "TransmitInterface.h"

using namespace System;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Collections::Generic;

namespace PMCommunication {

	public ref class CSerialPort : public CTransmitInterface
	{
	private:
		SerialPort^ m_SerialPort;
		array<Byte>^ m_arrayRecvBuffer;

	public:
		property String^ PortName
		{
			String^ get() 
			{ 
				return this->m_SerialPort->PortName; 
			}

			void set(String^ value) 
			{
				this->m_SerialPort->PortName = value; 
			}
		}

		property int BaudRate
		{
			int get() 
			{ 
				return this->m_SerialPort->BaudRate; 
			}

			void set(int value) 
			{
				this->m_SerialPort->BaudRate = value; 
			}
		}
		property int DataBits
		{
			int get() 
			{ 
				return this->m_SerialPort->DataBits; 
			}

			void set(int value) 
			{
				this->m_SerialPort->DataBits = value; 
			}
		}

		property System::IO::Ports::Parity Parity
		{
			System::IO::Ports::Parity get() 
			{ 
				return this->m_SerialPort->Parity; 
			}

			void set(System::IO::Ports::Parity value) 
			{
				this->m_SerialPort->Parity = value; 
			}
		}

		property System::IO::Ports::StopBits StopBits
		{
			System::IO::Ports::StopBits get() 
			{ 
				return this->m_SerialPort->StopBits; 
			}

			void set(System::IO::Ports::StopBits value) 
			{
				this->m_SerialPort->StopBits = value; 
			}
		}

		property int ReadBufferSize
		{
			int get() 
			{ 
				return this->m_SerialPort->ReadBufferSize; 
			}

			void set(int value) 
			{
				this->m_SerialPort->ReadBufferSize = value; 
			}
		}

		property int WriteBufferSize
		{
			int get() 
			{ 
				return this->m_SerialPort->WriteBufferSize; 
			}

			void set(int value) 
			{
				this->m_SerialPort->WriteBufferSize = value; 
			}
		}

		property int ReadTimeout
		{
			int get() 
			{ 
				return this->m_SerialPort->ReadTimeout; 
			}

			void set(int value) 
			{
				this->m_SerialPort->ReadTimeout = value; 
			}
		}

		property String^ ConnectionString
		{
			String^ get() 
			{ 
				System::Text::StringBuilder^ dbs = gcnew System::Text::StringBuilder();
				dbs->Append(String::Format("PortName={0};", this->PortName));
				dbs->Append(String::Format("BaudRate={0};", this->BaudRate));
				dbs->Append(String::Format("DataBits={0};", this->DataBits));
				dbs->Append(String::Format("Parity={0};", this->Parity));
				dbs->Append(String::Format("StopBits={0};", this->StopBits));
				dbs->Append(String::Format("ReadBufferSize={0};", this->ReadBufferSize));
				dbs->Append(String::Format("WriteBufferSize={0};", this->WriteBufferSize));
				dbs->Append(String::Format("ReadTimeout={0};", this->ReadTimeout));
				return dbs->ToString();
			}
			
			void set(String^ value) 
			{ 
				String^ dbs = value;
				if (dbs->EndsWith(";")) {
					dbs = value->Substring(0, dbs->Length - 1);
				}
				array<String^>^chunks = dbs->Split(';');
				System::Collections::IEnumerator^ myEnum = chunks->GetEnumerator();
				while (myEnum->MoveNext()) {
					String^ chunk = safe_cast<String^>(myEnum->Current);
					array<String^>^values = chunk->Split('=');
					if (values->Length == 2) {
						String^ txt = values[0]->Trim()->ToLower();
						if (txt == "PortName") this->PortName = values[1]->Trim(); 
						if (txt == "BaudRate") this->BaudRate = int::Parse(values[1]->Trim()); 
						if (txt == "DataBits") this->DataBits = int::Parse(values[1]->Trim()); 
						if (txt == "Parity") {
							Array^ a = Enum::GetValues(System::IO::Ports::Parity::typeid);
							Array^ b = Enum::GetNames(System::IO::Ports::Parity::typeid);
							for (int i=0; i<b->Length; i++) {
								if (b->GetValue(i) == values[1]->Trim()) {
									this->Parity = (System::IO::Ports::Parity) a->GetValue(i);
									break;
								}
							}
							delete b;
						}
						if (txt == "StopBits") {
							Array^ a = Enum::GetValues(System::IO::Ports::Parity::typeid);
							Array^ b = Enum::GetNames(System::IO::Ports::StopBits::typeid);
							for (int i=0; i<b->Length; i++) {
								if (b->GetValue(i) == values[1]->Trim()) {
									this->StopBits = (System::IO::Ports::StopBits) a->GetValue(i);
									break;
								}
							}
							delete b;
						}
						if (txt == "ReadBufferSize") this->ReadBufferSize = int::Parse(values[1]->Trim()); 
						if (txt == "WriteBufferSize") this->WriteBufferSize = int::Parse(values[1]->Trim()); 
						if (txt == "ReadTimeout") this->ReadTimeout = int::Parse(values[1]->Trim()); 
					}
				}
			}
		}

	public:
		CSerialPort();
		~CSerialPort();
		!CSerialPort();

	public:
		virtual void Connect() override;
		virtual void Disconnect(void) override;
		virtual bool IsConnected() override { return this->m_SerialPort->IsOpen; }
		virtual UInt64 Transmit(array<Byte> ^lpDataOut) override;
		virtual void Transmit(String^ cmdArduino) override; //Added By OP

		virtual void vLoadConfiguration(System::IO::BinaryReader ^lpReader) override;
		virtual void vSaveConfiguration(System::IO::BinaryWriter ^lpWriter) override;

		void Connect(String^ strPortName, int iBaudRate, System::IO::Ports::Parity parity, int iDataBit);
	private:
		void OnSerialPortDataReceived(Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);

	};
}
