#include "StdAfx.h"
#include "Bytes.h"

PMProtocol::CBytes::CBytes()
{
	this->m_lpDataBuf = gcnew List<Byte>;
}

PMProtocol::CBytes::~CBytes()
{
	this->m_lpDataBuf->Clear();
	delete this->m_lpDataBuf;
}

PMProtocol::CBytes::!CBytes()
{
	this->~CBytes();
}

Byte PMProtocol::CBytes::GetDataByte(int nIndex)
{
	return this->m_lpDataBuf[nIndex];
}

Int16 PMProtocol::CBytes::GetDataTailInt16()
{
	Int16 nValue = this->m_lpDataBuf[(this->m_lpDataBuf->Count-1)]<<8;
	nValue = nValue |  this->m_lpDataBuf[this->m_lpDataBuf->Count-2];
	return nValue;
}

int PMProtocol::CBytes::GetSize()
{
	return this->m_lpDataBuf->Count;
}

array<Byte>^ PMProtocol::CBytes::ToArray()
{
	return this->m_lpDataBuf->ToArray();
}

void PMProtocol::CBytes::AppendInt8(Byte value)
{
	this->m_lpDataBuf->Add(value);
}

void PMProtocol::CBytes::AppendInt16(Int16 value)
{
	AppendInt8((Byte) (value & 0x000000FF));
	AppendInt8((Byte) ((value & 0x0000FF00) >> 8));
}

void PMProtocol::CBytes::AppendInt24(Int32 value)
{
	AppendInt16(value);
	AppendInt8((Byte) ((value & 0x00FF0000) >> 16));
}

void PMProtocol::CBytes::AppendInt32(Int32 value)
{
	AppendInt24(value);
	AppendInt8((Byte) ((value & 0xFF000000) >> 24));
}

void PMProtocol::CBytes::AppendInt48(Int64 value)
{
	AppendInt32((Int32) value);
	AppendInt8((Byte) ((value & 0xFF000000) >> 32));
}

void PMProtocol::CBytes::AppendBytes(array<Byte>^ lpSourceData)
{
	this->m_lpDataBuf->AddRange(lpSourceData);
}

void PMProtocol::CBytes::AppendBytes(array<Byte>^ lpSourceData, int iOffset, int iCount)
{
	for (int i=iOffset; i<iOffset + iCount; i++) {
		this->AppendInt8(lpSourceData[i]);
	}
}

void PMProtocol::CBytes::AppendBytes(CBytes^ lpSourceData, int iOffset, int iCount)
{
	for (int i=iOffset; i<iOffset+iCount; i++) {
		this->AppendInt8(lpSourceData->GetDataByte(i));
	}
}

Byte PMProtocol::CBytes::RemoveInt8()
{
	if (GetSize() == 0) return 0;
	Byte byData = this->m_lpDataBuf[0];
	this->m_lpDataBuf->RemoveAt(0);

	return byData;
}

Int16 PMProtocol::CBytes::RemoveInt16()
{
	Int16 iData;
	iData = this->RemoveInt8();
	iData += this->RemoveInt8() << 8;
	return iData;
}

Int32 PMProtocol::CBytes::RemoveInt24()
{
	Int32 iData;
	iData = this->RemoveInt8();
	iData += this->RemoveInt8() << 8;
	iData += this->RemoveInt8() << 16;
	return iData;
}

Int32 PMProtocol::CBytes::RemoveInt32()
{
	Int32 iData;
	iData = this->RemoveInt8();
	iData += this->RemoveInt8() << 8;
	iData += this->RemoveInt8() << 16;
	iData += this->RemoveInt8() << 24;
	return iData;
}

Int64 PMProtocol::CBytes::RemoveInt48()
{
	Int64 iData, iData1, iData2;
	iData1 = RemoveInt24();
	iData2 = RemoveInt24();
	iData = (iData2 << 24) + iData1;

	return iData;
}

void PMProtocol::CBytes::RemoveBytes(int nLen)
{
	this->m_lpDataBuf->RemoveRange(0, nLen);
}
	
void PMProtocol::CBytes::RemoveTail(int nLen)
{
	for (int i=0; i<nLen; i++) {
		this->m_lpDataBuf->RemoveAt(this->m_lpDataBuf->Count - 1);
	}
}

void PMProtocol::CBytes::RemoveAll()
{
	this->m_lpDataBuf->Clear();
}
