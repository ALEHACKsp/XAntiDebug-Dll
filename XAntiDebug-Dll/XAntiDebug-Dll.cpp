// XAntiDebug-Dll.cpp : 定义 DLL 应用程序的导出函数。
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
	// 调用检测
	//

	for (;;)
	{
		result = antiDbg.XAD_ExecuteDetect();
		return result;
	}
}