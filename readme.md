This patch allows you to choose a network adapter at startup, like hamachi, for Rayman Arena to use in LAN mode.
The LAN init code in the game is not very good, which is why it has problems with multiple adapters, or adapters with adaper IP addresses in ranges it doesn't expect.
The patch NOPs out most of a couple of routines, and hardcodes into them the network adapter information selected.

It also adds basic discord rich presence support, showing you are playing rayman m/arena.

Copy the discord sdk into a directory named discord in the root of this repo.

In the visual studio native tools command prompt (or similar environment):

cl.exe /std:c++17 /Zi /LD discord/cpp/*.cpp patch.cpp /I\discord\cpp\  /link /OUT:arenapatch.asi user32.lib IPHLPAPI.lib Ws2_32.lib discord/lib/x86/discord_game_sdk.dll.lib

Use [Ultimate Asi Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader), with rayman arena and put arenapatch.asi into the plugins directory.

You may want to rename dinput8.dll from the asi loader to one of the other supported dll names.
The controller patch for arena on the pcwiki replaces dinput8.dll
