In the visual studio native tools command prompt (or similar environment):

cl.exe /Zi /LD lame.c /link /OUT:arenapatch.asi /DEBUG user32.lib IPHLPAPI.lib Ws2_32.lib

Use [Ultimate Asi Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader), with rayman arena and put arenapatch.asi into the plugins directory.

I used the dinput8.dll version.

This patch allows you to choose a network adapter at startup, like hamachi, for Rayman Arena to use in LAN mode.
The LAN init code in the game is not very good, which is why it has problems with multiple adapters, or adapters with adaper IP addresses in ranges it doesn't expect.
The patch NOPs out most of a couple of routines, and hardcodes into them the network adapter information selected.