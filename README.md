# WNDHELP32

WNDHELP32 is a utility header for Win32 API development. It provides shorthand macros and helper definitions to reduce boilerplate code and improve readability.

## Contents

### General Definitions
- MAX_PATH – Standard buffer size constant (260 characters).
- stringmax[MAX_PATH] – Fixed-length string typedef.

### Window Helpers
- MSGLOOP – Standard message loop macro.
- SHOWWND, UPDWND, SHOWANDUPDATE – Macros to show and update windows.
- DEFPARAMS – Shorthand for WinMain parameters.

### Calling Conventions
- CCALL – Expands to __cdecl.
- VECC – Expands to __vectorcall.
- THISC – Expands to __thiscall.

### Function Definitions
- FUNCNORET – Shorthand for void return type.
- ALLOW_CUSTOM_WINMAIN – Disables warning 4255 to allow custom WinMain definitions.

## Example Usage

```cpp
#include "WNDHELP32.h"

int WINAPI WinMain(DEFPARAMS) {
    HWND hwnd = CreateWindow(...);

    SHOWANDUPDATE;

    MSGLOOP;

    return 0;
}
