// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit


#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

using namespace ATL;


#include <atlbase.h>
#include <atlapp.h>


#include <atlcom.h>
#include <atlhost.h>
#include <atlwin.h>
#include <atlctl.h>
#include <atlmisc.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;


#define USE_TIMEBOMB		FALSE
#define TIMEBOMB_DATE_YEAR	2008
#define TIMEBOMB_DATE_MONTH	3
#define TIMEBOMB_DATE_DAY	5
inline __forceinline BOOL CheckTimeBomb()
{
	if(!USE_TIMEBOMB)
		return TRUE;

	SYSTEMTIME st = {0};
	SYSTEMTIME bomb = {0};
	bomb.wYear = TIMEBOMB_DATE_YEAR;
	bomb.wMonth = TIMEBOMB_DATE_MONTH;
	bomb.wDay = TIMEBOMB_DATE_DAY;
	FILETIME now = {0}, bombTime = {0};
	GetSystemTime(&st);
	SystemTimeToFileTime(&st, &now);
	SystemTimeToFileTime(&bomb, &bombTime);

	return CompareFileTime(&now, &bombTime) <= 0;
}