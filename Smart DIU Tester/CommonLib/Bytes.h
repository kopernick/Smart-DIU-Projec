#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace PMProtocol {
	public ref class CBytes
	{
	private:
		List<Byte>^ m_lpDataBuf;

	public:
		CBytes();
		~CBytes();
		!CBytes();

		Byte GetDataByte(int nIndex);		
		Int16 GetDataTailInt16();

		int GetSize();
		array<Byte>^ ToArray();
		void AppendInt8(Byte value);
		void AppendInt16(Int16 value);
		void AppendInt24(Int32 value);
		void AppendInt32(Int32 value);
		void AppendInt48(Int64 value);
		void AppendBytes(array<Byte>^ lpSourceData);
		void AppendBytes(array<Byte>^ lpSourceData, int iOffset, int iCount);
		void AppendBytes(CBytes^ lpSourceData, int iOffset, int iCount);

		Int64 RemoveInt48();
		Int32 RemoveInt32();
		Int32 RemoveInt24();
		Int16 RemoveInt16();
		Byte RemoveInt8();
		void RemoveBytes(int nLen);
		void RemoveTail(int nLen);
		void RemoveAll();
	};
}