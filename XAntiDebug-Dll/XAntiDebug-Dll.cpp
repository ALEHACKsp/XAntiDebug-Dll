// XAntiDebug-Dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "XAntiDebug.h"

XAD_STATUS		status;
XAntiDebug		antiDbg(GetModuleHandle(NULL), FLAG_FULLON);
BOOL			result;

extern "C" __declspec(dllexport) BOOL Protect_Init()
{
	status = antiDbg.XAD_Initialize();
	if (status != XAD_OK)
	{
		return FALSE;
	}

	//
	// ���ü��
	//

	for (;;)
	{
		result = antiDbg.XAD_ExecuteDetect();
		return result;
	}
}