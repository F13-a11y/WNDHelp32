#pragma once

#define WNDHELP32_H
#define _WNDHELP32_H_

/* VERSION CHANGELOG */

#define WNDHELP32_VERSION_MAJOR 1
#define WNDHELP32_VERSION_MINOR 1
#define WNDHELP32_VERSION_PATCH 0
#define WNDHELP32_VERSION_STR "1.1.0"

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

#if defined(_WIN32) || defined(_WIN64)

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
#define STDC __stdcall

#define NONE 0
#define HEXEND 0xFFFFFFFF

#define nul_ptr nullptr

#define INTLONG __int64
/* ADD WINDOWS HEADER (Windows.h) TO USE THIS */


#define WAPI WINAPI 
#define hres HRESULT
#define hins HINSTANCE
#define WINBOOL BOOL

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

typedef const char* stringmax;
#define BIT(n) (1U << (n))
#define SET_FLAG(var, flag)   ((var) |= (flag))
#define CLEAR_FLAG(var, flag) ((var) &= ~(flag))
#define CHECK_FLAG(var, flag) (((var) & (flag)) != 0)

#define MAXBUF char buffer[MAX_PATH]

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

#define GETDLLFUNC __declspec(dllimport)
#define OPENFUNCEXTR __declspec(dllexport)

#define NODISC [[nodiscard]]

#define inl inline
#define inlmsvc __inline
#define forceinl __forceinline

#define winapireq WIN32_LEAN_AND_MEAN

#define inlasm __asm

#define flscr __pragma fenv_access(on)

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
/* FOR DEBUG ONLY */

#define stackovf void stackovf() {stackovf();}

#define bufovf char buf[8] \
        strcpy(buf,"Lorem ipsum dolar sit ames.");

#pragma endregion // WNDHelp32
#pragma region OFNFILTERS
#define FILTER_ALL        TEXT("All Files\0*.*\0")
#define FILTER_TEXT       TEXT("Text Files\0*.txt\0")
#define FILTER_CPP        TEXT("C++ Source\0*.cpp;*.h\0")
#define FILTER_C          TEXT("C Source\0*.c;*.h\0")
#define FILTER_HEADER     TEXT("Header Files\0*.h;*.hpp\0")
#define FILTER_SCRIPT     TEXT("Scripts\0*.bat;*.ps1;*.sh\0")
#define FILTER_CONFIG     TEXT("Config Files\0*.ini;*.cfg\0")
#define FILTER_LOG        TEXT("Log Files\0*.log\0")
#define FILTER_JSON       TEXT("JSON Files\0*.json\0")
#define FILTER_XML        TEXT("XML Files\0*.xml\0")
#define FILTER_DOC        TEXT("Word Documents\0*.doc;*.docx\0")
#define FILTER_PDF        TEXT("PDF Files\0*.pdf\0")
#define FILTER_XLS        TEXT("Excel Files\0*.xls;*.xlsx\0")
#define FILTER_PPT        TEXT("PowerPoint Files\0*.ppt;*.pptx\0")
#define FILTER_MARKDOWN   TEXT("Markdown\0*.md\0")
#define FILTER_RTF        TEXT("Rich Text\0*.rtf\0")
#define FILTER_LATEX      TEXT("LaTeX\0*.tex\0")
#define FILTER_CSV        TEXT("CSV Files\0*.csv\0")
#define FILTER_EPUB       TEXT("eBook EPUB\0*.epub\0")
#define FILTER_ODT        TEXT("OpenDocument\0*.odt\0")
#define FILTER_IMAGES     TEXT("Images\0*.png;*.jpg;*.bmp;*.gif\0")
#define FILTER_PNG        TEXT("PNG Images\0*.png\0")
#define FILTER_JPG        TEXT("JPEG Images\0*.jpg;*.jpeg\0")
#define FILTER_BMP        TEXT("Bitmap\0*.bmp\0")
#define FILTER_GIF        TEXT("GIF Images\0*.gif\0")
#define FILTER_TIFF       TEXT("TIFF Images\0*.tif;*.tiff\0")
#define FILTER_SVG        TEXT("SVG Vector\0*.svg\0")
#define FILTER_WEBP       TEXT("WebP Images\0*.webp\0")
#define FILTER_RAW        TEXT("RAW Photos\0*.raw;*.nef;*.cr2\0")
#define FILTER_ICON       TEXT("Icons\0*.ico\0")
#define FILTER_AUDIO      TEXT("Audio\0*.mp3;*.wav;*.flac;*.aac\0")
#define FILTER_MP3        TEXT("MP3 Audio\0*.mp3\0")
#define FILTER_WAV        TEXT("WAV Audio\0*.wav\0")
#define FILTER_FLAC       TEXT("FLAC Audio\0*.flac\0")
#define FILTER_AAC        TEXT("AAC Audio\0*.aac\0")
#define FILTER_OGG        TEXT("OGG Audio\0*.ogg\0")
#define FILTER_MIDI       TEXT("MIDI Files\0*.mid;*.midi\0")
#define FILTER_WMA        TEXT("WMA Audio\0*.wma\0")
#define FILTER_OPUS       TEXT("Opus Audio\0*.opus\0")
#define FILTER_AIFF       TEXT("AIFF Audio\0*.aiff\0")
#define FILTER_VIDEO      TEXT("Video\0*.mp4;*.avi;*.mkv;*.mov\0")
#define FILTER_MP4        TEXT("MP4 Video\0*.mp4\0")
#define FILTER_AVI        TEXT("AVI Video\0*.avi\0")
#define FILTER_MKV        TEXT("Matroska\0*.mkv\0")
#define FILTER_MOV        TEXT("QuickTime\0*.mov\0")
#define FILTER_WMV        TEXT("WMV Video\0*.wmv\0")
#define FILTER_FLV        TEXT("Flash Video\0*.flv\0")
#define FILTER_WEBM       TEXT("WebM Video\0*.webm\0")
#define FILTER_MPEG       TEXT("MPEG Video\0*.mpg;*.mpeg\0")
#define FILTER_TS         TEXT("Transport Stream\0*.ts\0")
#define FILTER_ARCHIVE    TEXT("Archives\0*.zip;*.rar;*.7z;*.tar;*.gz\0")
#define FILTER_ZIP        TEXT("ZIP Files\0*.zip\0")
#define FILTER_RAR        TEXT("RAR Files\0*.rar\0")
#define FILTER_7Z         TEXT("7-Zip Files\0*.7z\0")
#define FILTER_TAR        TEXT("TAR Files\0*.tar\0")
#define FILTER_GZ         TEXT("GZip Files\0*.gz\0")
#define FILTER_BZ2        TEXT("BZip2 Files\0*.bz2\0")
#define FILTER_ISO        TEXT("ISO Images\0*.iso\0")
#define FILTER_CAB        TEXT("CAB Files\0*.cab\0")
#define FILTER_ARJ        TEXT("ARJ Files\0*.arj\0")
#define FILTER_LZH        TEXT("LZH Files\0*.lzh\0")
#define FILTER_HTML       TEXT("HTML Files\0*.html;*.htm\0")
#define FILTER_JS         TEXT("JavaScript\0*.js\0")
#define FILTER_TSCRIPT    TEXT("TypeScript\0*.ts\0")
#define FILTER_PY         TEXT("Python\0*.py\0")
#define FILTER_JAVA       TEXT("Java\0*.java\0")
#define FILTER_CS         TEXT("C#\0*.cs\0")
#define FILTER_GO         TEXT("Go\0*.go\0")
#define FILTER_RB         TEXT("Ruby\0*.rb\0")
#define FILTER_PHP        TEXT("PHP\0*.php\0")
#define FILTER_SWIFT      TEXT("Swift\0*.swift\0")
#define FILTER_DLL        TEXT("DLL Files\0*.dll\0")
#define FILTER_EXE        TEXT("Executable\0*.exe\0")
#define FILTER_SYS        TEXT("System Files\0*.sys\0")
#define FILTER_DRV        TEXT("Driver Files\0*.drv\0")
#define FILTER_OCX        TEXT("ActiveX Controls\0*.ocx\0")
#define FILTER_COM        TEXT("COM Files\0*.com\0")
#define FILTER_BIN        TEXT("Binary Files\0*.bin\0")
#define FILTER_DAT        TEXT("Data Files\0*.dat\0")
#define FILTER_OBJ        TEXT("Object Files\0*.obj\0")
#define FILTER_LIB        TEXT("Library Files\0*.lib\0")
#define FILTER_TMP        TEXT("Temporary Files\0*.tmp\0")
#define FILTER_BACKUP     TEXT("Backup Files\0*.bak\0")
#define FILTER_FONT       TEXT("Fonts\0*.ttf;*.otf\0")
#define FILTER_PS         TEXT("Photoshop\0*.psd\0")
#define FILTER_AI         TEXT("Illustrator\0*.ai\0")
#define FILTER_XCF        TEXT("GIMP\0*.xcf\0")
#define FILTER_APK        TEXT("Android APK\0*.apk\0")
#define FILTER_IPA        TEXT("iOS IPA\0*.ipa\0")
#define FILTER_DB         TEXT("Database\0*.db;*.sqlite\0")
#define FILTER_LOGS       TEXT("System Logs\0*.log\0")

#pragma endregion
#pragma region FUNCS

// FUNCTIONS
#include <Windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <tchar.h>

HANDLE AttachProc(DWORD pid) {
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    return hProc;
}

DWORD GetPidByProcessName(const std::wstring& exeName) {
    DWORD pid = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return 0;

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (_wcsicmp(pe32.szExeFile, exeName.c_str()) == 0) {
                pid = pe32.th32ProcessID;
                break;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return pid;
}

void ShowOpenFileDialog(HWND hwnd, LPCTSTR filter) {
    OPENFILENAME ofn;
    TCHAR szFile[MAX_PATH];

    ZeroMemory(&ofn, sizeof(ofn));
    ZeroMemory(szFile, sizeof(szFile));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    /*

    if (GetOpenFileName(&ofn)) {
        _tprintf(TEXT("Example String"));
    } else {
        _tprintf(TEXT("Example String"));
    }

    */

}

/*10 -> Windows 10
  11 -> Windows 11*/
int WinVer() {
    OSVERSIONINFOEXW osvi;
    ZeroMemory(&osvi, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);

    typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);
    RtlGetVersionPtr fn = (RtlGetVersionPtr)GetProcAddress(
        GetModuleHandleW(L"ntdll.dll"), "RtlGetVersion");

    if (fn != nullptr) {
        fn((PRTL_OSVERSIONINFOW)&osvi);
        if (osvi.dwBuildNumber > 22000) {
            return 11;
        }
        else {
            return 10;
        }
    }

    return 0;
} 

bool isPositive(int n) {
    return n > 0;
}


// TODO : MAKE NEW FUNCS



#pragma endregion

void ShowOpenFileDialog(HWND hwnd, LPCTSTR filter);
int WinVer();
HANDLE AttachProc(DWORD pid);
DWORD GetPidByProcessName(const std::wstring& exeName);
bool isPositive(int n);


#else
#warning "WNDHelp32 is only for Windows Platform."
#define BUILDER F13-a11y
#endif

/*
Copyright (c) 2026 F13-a11y
*/
