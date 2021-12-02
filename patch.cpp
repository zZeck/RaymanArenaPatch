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
#include <winnls.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <locale>
#include <codecvt>
#include <string>
#include <vector>

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

IP_ADAPTER_ADDRESSES *pAddresses;
int selectedIndex = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OpenAdapterSelectDialog(HINSTANCE hInstDll);
bool LoadPrior();
void LoadAdapters();
void Patch(PIP_ADAPTER_UNICAST_ADDRESS_LH addr);

extern __declspec(dllexport) INT APIENTRY DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            LoadAdapters();
            if(!LoadPrior())
                OpenAdapterSelectDialog(hInstDll);
            delete(pAddresses);
	        break;
        }
    }
    return TRUE;
}

bool LoadPrior()
{
    std::wifstream settings(std::filesystem::path("adapter.txt"));
    settings.imbue(std::locale(settings.getloc(), new std::codecvt_utf8_utf16<wchar_t, 0x10FFFF, std::consume_header>));

    std::wstring line;
    std::getline(settings, line);
    settings.close();

    const auto normalizedSize = NormalizeString(NORM_FORM::NormalizationC, line.c_str(), -1, nullptr, 0);

    std::vector<wchar_t> normalizedString(normalizedSize);
    const auto error = NormalizeString(NORM_FORM::NormalizationC, line.c_str(), -1, normalizedString.data(), normalizedSize);

    std::wstring adapterName(normalizedString.data());

    auto pCurrAddresses = pAddresses;

    while (pCurrAddresses)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> converter;
        //convert friendlyname to utf8
        auto utf8 = converter.to_bytes(pCurrAddresses->FriendlyName);

        //convert back to utf16
        auto utf16 = converter.from_bytes(utf8);

        //normalize
        const auto normalizedFriendlyNameSize = NormalizeString(NORM_FORM::NormalizationC, utf16.c_str(), -1, nullptr, 0);

        std::vector<wchar_t> normalizedFriendlynameString(normalizedFriendlyNameSize);
        const auto friendlyNameError = NormalizeString(NORM_FORM::NormalizationC, utf16.c_str(), -1, normalizedFriendlynameString.data(), normalizedFriendlyNameSize);

        std::wstring friendlyName(normalizedFriendlynameString.data());

        //wstring compare with adapterName
        if(adapterName == friendlyName)
        {
            Patch(pCurrAddresses->FirstUnicastAddress);
            return true;
        }

        pCurrAddresses = pCurrAddresses->Next;
    }
    return false;
}

void LoadAdapters()
{
    ULONG size = 0;

    auto status = GetAdaptersAddresses(AF_INET, 0, NULL, NULL, &size);

    pAddresses = new IP_ADAPTER_ADDRESSES[size];

    status = GetAdaptersAddresses(AF_INET, 0, NULL, pAddresses, &size);
}

void OpenAdapterSelectDialog(HINSTANCE hInstDll)
{
    const TCHAR *CLASS_NAME = TEXT("Adapter Select");

    WNDCLASS wc = { 0 };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstDll;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    auto hwnd = CreateWindowEx(
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

    auto hWndListBox = CreateWindowEx(
        0,
        WC_LISTBOX,
        TEXT(""),
        WS_VISIBLE|WS_CHILD|WS_VSCROLL|LBS_NOTIFY,
        xpos, ypos, nwidth, nheight,
        hwndParent,
        NULL,
        hInstDll,
        NULL);

    //keep the start of the list in pAddresses
    auto *pCurrAddresses = pAddresses;

    while (pCurrAddresses)
    {
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
}

//https://github.com/ianpatt/f4se/blob/34dd7e92227e2c027e3910631ac7b7478c3fe6c5/f4se_common/SafeWrite.cpp
void SafeWriteBuf(uintptr_t addr, void * data, size_t len)
{
	DWORD oldProtect;

	VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((void *)addr, data, len);
	VirtualProtect((void *)addr, len, oldProtect, &oldProtect);
}

void Patch(PIP_ADAPTER_UNICAST_ADDRESS_LH addr)
{
    SafeWriteBuf(patchOneStart, patchOne, sizeof(patchOne));
    SafeWriteBuf(patchTwoStart, patchTwo, sizeof(patchTwo));

    auto ipAddrArray = (unsigned char *)addr->Address.lpSockaddr->sa_data;

    unsigned int octal0 = ipAddrArray[5] << 24;
    unsigned int octal1 = ipAddrArray[4] << 16;
    unsigned int octal2 = ipAddrArray[3] << 8;
    unsigned int octal3 = ipAddrArray[2] << 0;

    auto ipAddress = octal0 | octal1 | octal2 | octal3;

    ULONG netmask;

    ConvertLengthToIpv4Mask(addr->OnLinkPrefixLength, &netmask);

    SafeWriteBuf(patchOneIpLocation, &ipAddress, sizeof(ipAddress));
    SafeWriteBuf(patchOneNetMaskLocation, &netmask, sizeof(netmask));
    SafeWriteBuf(patchTwoIpLocation, &ipAddress, sizeof(ipAddress));
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        auto command = HIWORD(wParam);
        auto childHWnd = (HWND)(lParam);
        switch (command)
        {
            case(LBN_SELCHANGE):
                selectedIndex = SendMessage(childHWnd, (UINT) LB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
                break;
           case(BN_CLICKED):
                auto addr = pAddresses;

                for(int i = 0; i < selectedIndex; i++){
                    addr = addr->Next;
                }

                Patch(addr->FirstUnicastAddress);

                std::wofstream settings(std::filesystem::path("adapter.txt"));
                settings.imbue(std::locale(settings.getloc(), new std::codecvt_utf8_utf16<wchar_t, 0x10FFFF, std::consume_header>));

                settings << addr->FriendlyName << std::endl;
                settings.close();

                PostMessage(hwnd, WM_CLOSE, 0, 0);
                break;
        }
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
