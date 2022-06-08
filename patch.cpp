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
#include <pathcch.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <locale>
#include <codecvt>
#include <string>
#include <vector>
#include <thread>
#include "discord/cpp/discord.h"

constexpr unsigned int patchOneStart = 0x4C14E0;
constexpr unsigned char patchOne[] = {
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
constexpr unsigned int patchOneIpLocation = 0x4C1556;
constexpr unsigned int patchOneNetMaskLocation = 0x4C155B;

constexpr unsigned int patchTwoStart = 0x4c1380;
constexpr unsigned char patchTwo[] = {
0x9C, 0x24, 0x98, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
0x90, 0x90, 0x90, 0x90, 0x90, 0xB8, 0xC0, 0xA8, 0x01, 0x06, 0x68, 0x81, 0x00, 0x00, 0x00, 0x50,
};
constexpr unsigned int patchTwoIpLocation = 0x4C13B6;

IP_ADAPTER_ADDRESSES *pAddresses;
int selectedIndex = 0;

std::filesystem::path configFilePath;

discord::Core* core{};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OpenAdapterSelectDialog(HINSTANCE hInstDll);
bool LoadPrior();
void LoadAdapters();
void Patch(PIP_ADAPTER_UNICAST_ADDRESS_LH addr);
void Discord();

auto exiting = false;

extern __declspec(dllexport) INT APIENTRY DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            wchar_t path[MAX_PATH];
            const auto getModuleError = GetModuleFileNameW(nullptr, path, MAX_PATH);
            configFilePath = std::filesystem::path(path);
            configFilePath.remove_filename();
            configFilePath.append("arenaPatch.cfg");
            LoadAdapters();
            if(!LoadPrior())
                OpenAdapterSelectDialog(hInstDll);
            delete(pAddresses);

            auto hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Discord, 0, 0, 0);

	        break;
        }
        case DLL_PROCESS_DETACH:
            exiting = true;
            break;
    }
    return TRUE;
}

void Discord()
{
    discord::ClientId CLIENT_ID(983113098980364359);
    auto result = discord::Core::Create(CLIENT_ID, DiscordCreateFlags_Default, &core);

    discord::Activity activity{};
    activity.SetType(discord::ActivityType::Playing);
    activity.GetAssets().SetLargeImage("raymanmarena");
    activity.GetAssets().SetLargeText("Join the community: https://discord.gg/qp5S83ZhgW");
    activity.GetAssets().SetSmallText("Join the community: https://discord.gg/qp5S83ZhgW");
    activity.GetTimestamps().SetStart(std::time(nullptr));
    core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {

    });

    while (!exiting)
	{
		core->RunCallbacks();
        const auto delay = 5000;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

bool LoadPrior()
{
    std::wifstream settings(configFilePath);
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
        //convert friendlyname to utf8.
        //windows does not usually validate utf16 (for example with file paths), I assume it doesn't for the FriendlyName.
        //roundtrip the string to utf8 and back to utf16 with default char generated for bad surrogates and other garbage.
        //that way it will match what is saved in the file
        //though, I'm not sure how the codecvt handles bad chars, and it's deprecated
        //should have used the windows os converter functions
        const auto utf8 = converter.to_bytes(pCurrAddresses->FriendlyName);

        //convert back to utf16
        const auto utf16 = converter.from_bytes(utf8);

        //normalize, so comparison will work.
        //If other programs edit the text, there is no guarantee the normalization will match what was saved in the friendly name
        const auto normalizedFriendlyNameSize = NormalizeString(NORM_FORM::NormalizationC, utf16.c_str(), -1, nullptr, 0);

        std::vector<wchar_t> normalizedFriendlynameString(normalizedFriendlyNameSize);
        const auto friendlyNameError = NormalizeString(NORM_FORM::NormalizationC, utf16.c_str(), -1, normalizedFriendlynameString.data(), normalizedFriendlyNameSize);

        std::wstring friendlyName(normalizedFriendlynameString.data());

        //== is just going to compare ordinals/wchar_ts/code units, so normalization needed first
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
    unsigned long size = 0;

    const auto statusGetSize = GetAdaptersAddresses(AF_INET, 0, nullptr, nullptr, &size);

    pAddresses = new IP_ADAPTER_ADDRESSES[size];

    const auto status = GetAdaptersAddresses(AF_INET, 0, nullptr, pAddresses, &size);
}

void OpenAdapterSelectDialog(const HINSTANCE hInstDll)
{
    const auto CLASS_NAME = L"Adapter Select";

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
    nullptr,
    nullptr,
    hInstDll,
    nullptr
    );

    ShowWindow(hwnd, SW_SHOW);

    int xpos = 30;
    int ypos = 30;
    int nwidth = 340;
    int nheight = 300;

    auto hWndListBox = CreateWindowEx(
        0,
        WC_LISTBOX,
        TEXT(""),
        WS_VISIBLE|WS_CHILD|WS_VSCROLL|LBS_NOTIFY,
        xpos, ypos, nwidth, nheight,
        hwnd,
        nullptr,
        hInstDll,
        nullptr);

    //keep the start of the list in pAddresses
    auto pCurrAddresses = pAddresses;

    while (pCurrAddresses)
    {
        SendMessageW(hWndListBox,(UINT) LB_ADDSTRING,(WPARAM) 0,(LPARAM) pCurrAddresses->FriendlyName);

        pCurrAddresses = pCurrAddresses->Next;
    }

    SendMessageW(hWndListBox, LB_SETCURSEL, (WPARAM)0, (LPARAM)0);

    auto hwndButton = CreateWindowExW(
        0,
        L"BUTTON",
        L"OK",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        163,
        320,
        75,
        23,
        hwnd,
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
void SafeWriteBuf(const uintptr_t addr, const void * data, const size_t len)
{
	DWORD oldProtect;

	VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((void *)addr, data, len);
	VirtualProtect((void *)addr, len, oldProtect, &oldProtect);
}

void Patch(const PIP_ADAPTER_UNICAST_ADDRESS_LH addr)
{
    SafeWriteBuf(patchOneStart, patchOne, sizeof(patchOne));
    SafeWriteBuf(patchTwoStart, patchTwo, sizeof(patchTwo));

    auto ipAddrArray = (unsigned char *)addr->Address.lpSockaddr->sa_data;

    unsigned int octal0 = ipAddrArray[5] << 24;
    unsigned int octal1 = ipAddrArray[4] << 16;
    unsigned int octal2 = ipAddrArray[3] << 8;
    unsigned int octal3 = ipAddrArray[2] << 0;

    auto ipAddress = octal0 | octal1 | octal2 | octal3;

    unsigned long netmask;

    ConvertLengthToIpv4Mask(addr->OnLinkPrefixLength, &netmask);

    SafeWriteBuf(patchOneIpLocation, &ipAddress, sizeof(ipAddress));
    SafeWriteBuf(patchOneNetMaskLocation, &netmask, sizeof(netmask));
    SafeWriteBuf(patchTwoIpLocation, &ipAddress, sizeof(ipAddress));
}

LRESULT CALLBACK WindowProc(const HWND hwnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam)
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

                std::wofstream settings(configFilePath);
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
