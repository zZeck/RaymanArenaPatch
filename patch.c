#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <commctrl.h>
#include <iphlpapi.h>
#include <stdio.h>

int patchOneStart = 0x4C14E0;
char patchOne[] = {
0x30, 0x0F, 0x84, 0xDE, 0x01, 0x00, 0x00, 0x53, 0x57, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0xBD, 0xC0, 0xA8, 0x01, 0x06, 0xBA, 0xFF, 0xFF, 0xFF, 0x00, 0x89,
0x6C, 0x24, 0x20, 0x89, 0x54, 0x24, 0x30, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x8B, 0x4C, 0x24, 0x38, 0x51, 0xFF, 0x15, 0xE0, 0xD3, 0x5A, 0x00,
};
int patchOneIpLocation = 0x4C1556;
int patchOneNetMaskLocation = 0x4C155B;

int patchTwoStart = 0x4c1380;
char patchTwo[] = {
0x9C, 0x24, 0x98, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0xB8, 0xC0, 0xA8, 0x01, 0x06, 0x68, 0x81, 0x00, 0x00, 0x00, 0x50,
};
int patchTwoIpLocation = 0x4C13B6;

IP_ADAPTER_ADDRESSES pAddresses[10];
int selectedIndex = 0;

HANDLE hLogFile;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OpenAdapterSelectDialog(HINSTANCE hInstDll);

extern __declspec(dllexport) INT APIENTRY DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    hLogFile = CreateFile(TEXT("log.txt"),
                       GENERIC_WRITE,
                       0,
                       NULL,
                       CREATE_NEW,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL);

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            OpenAdapterSelectDialog(hInstDll);
	        break;
        }
    }
    return TRUE;
}

void OpenAdapterSelectDialog(HINSTANCE hInstDll)
{
    char beforeUI[33] = "Before Adapter Select Creation\n";
    int bytesWritten = 0;
    WriteFile(
      hLogFile,
      beforeUI,
      sizeof(beforeUI),
      &bytesWritten,
      NULL);

    const TCHAR *CLASS_NAME = TEXT("Adapter Select");

    WNDCLASS wc = { 0 };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstDll;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
    0,
    CLASS_NAME,
    L"Select Adapter",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    400,
    400,
    NULL,
    NULL,
    hInstDll,
    NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    int xpos = 30;
    int ypos = 30;
    int nwidth = 340;
    int nheight = 300;
    HWND hwndParent =  hwnd;

    HWND hWndListBox = CreateWindowEx(
        0,
        WC_LISTBOX,
        TEXT(""),
        WS_VISIBLE|WS_CHILD|WS_VSCROLL|LBS_NOTIFY,
        xpos, ypos, nwidth, nheight,
        hwndParent,
        NULL,
        hInstDll,
        NULL);

    PULONG size = sizeof(pAddresses);

    char beforeGetAdapters[] = "Before GetAdaptersAddresses call\n";
    bytesWritten = 0;
    WriteFile(
      hLogFile,
      beforeGetAdapters,
      sizeof(beforeGetAdapters),
      &bytesWritten,
      NULL);

    ULONG status = GetAdaptersAddresses(AF_INET, 0, NULL, pAddresses, &size);

    //keep the start of the list in pAddresses
    IP_ADAPTER_ADDRESSES *pCurrAddresses = pAddresses;

    while (pCurrAddresses)
    {
        bytesWritten = 0;
        WriteFile(
          hLogFile,
          pCurrAddresses->FriendlyName,
          wcslen(pCurrAddresses->FriendlyName),
          &bytesWritten,
          NULL);
        
        char newLine[] = "\n";
        WriteFile(
          hLogFile,
          newLine,
          wcslen(newLine),
          &bytesWritten,
          NULL);

        SendMessage(hWndListBox,(UINT) LB_ADDSTRING,(WPARAM) 0,(LPARAM) pCurrAddresses->FriendlyName);

        pCurrAddresses = pCurrAddresses->Next;
    }

    SendMessage(hWndListBox, LB_SETCURSEL, (WPARAM)0, (LPARAM)0);

    HWND hwndButton = CreateWindowEx(
        0,
        TEXT("BUTTON"),
        TEXT("OK"),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        163,
        320,
        75,
        23,
        hwndParent,
        NULL,
        hInstDll,
        NULL);

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    CloseHandle(hLogFile);
}

//https://github.com/ianpatt/f4se/blob/34dd7e92227e2c027e3910631ac7b7478c3fe6c5/f4se_common/SafeWrite.cpp
void SafeWriteBuf(uintptr_t addr, void * data, size_t len)
{
	int	oldProtect;

	VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((void *)addr, data, len);
	VirtualProtect((void *)addr, len, oldProtect, &oldProtect);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        u_int command = HIWORD(wParam);
        HWND childHWnd = lParam;
        switch (command)
        {
            case(LBN_SELCHANGE):
                selectedIndex = SendMessage(childHWnd, (UINT) LB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
                break;
           case(BN_CLICKED):
                SafeWriteBuf(patchOneStart, patchOne, sizeof(patchOne));
                SafeWriteBuf(patchTwoStart, patchTwo, sizeof(patchTwo));

                IP_ADAPTER_ADDRESSES addr = pAddresses[selectedIndex];

                BYTE *physAddr = addr.PhysicalAddress;

                int ipAddress = (physAddr[2]) | (physAddr[3] << 8) | (physAddr[4] << 16) | (physAddr[5] << 24);

                int netmask;

                ConvertLengthToIpv4Mask(addr.FirstUnicastAddress->OnLinkPrefixLength, &netmask);

                SafeWriteBuf(patchOneIpLocation, &ipAddress, sizeof(ipAddress));
                SafeWriteBuf(patchOneNetMaskLocation, &netmask, sizeof(netmask));
                SafeWriteBuf(patchTwoIpLocation, &ipAddress, sizeof(ipAddress));

                PostMessage(hwnd, WM_CLOSE, 0, 0);
                break;
        }
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
