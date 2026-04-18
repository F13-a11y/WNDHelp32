#pragma once

#define WNDHELP32_H
#define _WNDHELP32_H_

/* VERSION CHANGELOG */

#define WNDHELP32_VERSION_MAJOR 1
#define WNDHELP32_VERSION_MINOR 0
#define WNDHELP32_VERSION_PATCH 0
#define WNDHELP32_VERSION_STR "1.0.0"

#pragma region MSVC_CHECK

#ifndef _MSC_VER
#error "WNDHelp32 is compatible with only MSVC"
#endif

/*    ONLY WORKS WITH VER 1400    */
#if _MSC_VER < 1400
#error "MSVC is outdated! WNDHelp32 requires Visual Studio 2005 (_MSC_VER 1400) or higher."
#endif

#if _MSC_VER >= 1930
#define WNDHELPER_MSVC2022
#elif _MSC_VER >= 1920
#define WNDHELPER_MSVC2019
#elif _MSC_VER >= 1910
#define WNDHELPER_MSVC2017
#elif _MSC_VER >= 1900
#define WNDHELPER_MSVC2015
#elif _MSC_VER >= 1800
#define WNDHELPER_MSVC2013
#elif _MSC_VER >= 1700
#define WNDHELPER_MSVC2012
#elif _MSC_VER >= 1600
#define WNDHELPER_MSVC2010
#elif _MSC_VER >= 1500
#define WNDHELPER_MSVC2008
#else
#define WNDHELPER_MSVC2005
#endif

#pragma endregion

#if defined(_WIN64)
#define WNDHELPER_PLATFORM_X64
#else
#define WNDHELPER_PLATFORM_X86
#endif


#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#pragma region WNDHELPER

#define MSGLOOP \
    MSG msg; \
    while(GetMessage(&msg, NULL, 0, 0) > 0) { \
        TranslateMessage(&msg); \
        DispatchMessage(&msg); \
    }

#define SHOWWND ShowWindow(hwnd, nCmdShow);
#define UPDWND UpdateWindow(hwnd);
#define SHOWANDUPDATE ShowWindow(hwnd, nCmdShow); UpdateWindow(hwnd);

#define DEFPARAMS \
    HINSTANCE hInstance, \
    HINSTANCE hPrevInstance, \
    LPSTR lpCmdLine, \
    int nCmdShow

#define CCALL __cdecl
#define VECC __vectorcall
#define THISC __thiscall
#define FUNCNORET void

#define ALLOW_CUSTOM_WINMAIN __pragma(warning(disable:4255))

#pragma region INTEGER

#ifndef INT32_MAX
#define INT32_MAX  2147483647
#define INT32_MIN -2147483648
#define UINT32_MAX 4294967295U
#define UINT32_MIN 0
#endif

#ifndef INT64_MAX
#define INT64_MAX  9223372036854775807LL
#define INT64_MIN (-9223372036854775807LL - 1)
#define UINT64_MAX 18446744073709551615ULL
#define UINT64_MIN 0
#endif
#ifndef INT8_MAX
#define INT8_MAX   127
#define INT8_MIN  -128
#define UINT8_MAX  255U
#define UINT8_MIN  0
#endif

#ifndef INT16_MAX
#define INT16_MAX   32767
#define INT16_MIN  -32768
#define UINT16_MAX  65535U
#define UINT16_MIN  0
#endif

#ifndef INT4_MAX
#define INT4_MAX   7
#define INT4_MIN  -8
#define UINT4_MAX  15U
#define UINT4_MIN  0
#endif


#pragma endregion

typedef const char* stringmax[MAX_PATH];

#define BIT(n) (1U << (n))
#define SET_FLAG(var, flag)   ((var) |= (flag))
#define CLEAR_FLAG(var, flag) ((var) &= ~(flag))
#define CHECK_FLAG(var, flag) (((var) & (flag)) != 0)


#define SAFE_DELETE(p) if((p)!=NULL){ delete (p); (p)=NULL; }
#define SAFE_FREE(p)   if((p)!=NULL){ free(p); (p)=NULL; }
#define IS_NULL(p)     ((p)==NULL)
#define NOT_NULL(p)    ((p)!=NULL)

#define STRBUF(name) char name[MAX_PATH]
#define STRCPY_SAFE(dest, src) strncpy(dest, src, MAX_PATH-1); dest[MAX_PATH-1] = '\0';

#define DBGPRINT(msg) OutputDebugStringA(msg)
#define DBGPRINTW(msg) OutputDebugStringW(msg)


#define PACKED_STRUCT(name) __pragma(pack(push, 1)) struct name __pragma(pack(pop))

#define WNDDHANDLE_QUIT case WM_QUIT: return 0;
#define WNDHANDLE_CLOSE case WM_CLOSE: DestroyWindow(hwnd); break;




#pragma region SCM_DRIVER
/* KERNEL DRIVER MACROS */
#define SERVICE_KERNEL_DRIVER   0x00000001
#define SERVICE_FILE_SYSTEM     0x00000002

#define SERVICE_BOOT_START      0x00000000
#define SERVICE_SYSTEM_START    0x00000001
#define SERVICE_AUTO_START      0x00000002
#define SERVICE_DEMAND_START    0x00000003
#define SERVICE_DISABLED        0x00000004

#define SERVICE_ERROR_IGNORE    0x00000000
#define SERVICE_ERROR_NORMAL    0x00000001
#define SERVICE_ERROR_SEVERE    0x00000002
#define SERVICE_ERROR_CRITICAL  0x00000003

#define SC_MANAGER_ALL_ACCESS   0xF003F
#define SERVICE_ALL_ACCESS      0xF01FF

#pragma endregion

#pragma region MSGBOX_HELPERS

#define MSGBOX_PARENT(hwnd) (hwnd)
#define MSGBOX_NOPARENT     (NULL)

/* For MessageBox and types */
#define OK           MB_OK
#define OKCANCEL     MB_OKCANCEL
#define YESNO        MB_YESNO
#define ABORTRETRYCANCEL MB_ABORTRETRYCANCEL
#define ICINFO    MB_ICONINFORMATION
#define ICWARN     MB_ICONWARNING
#define ICERR    MB_ICONERROR

#pragma endregion

#pragma endregion // WNDHelp32

/*


Copyright (c) 2026 F13-a11y


*/

