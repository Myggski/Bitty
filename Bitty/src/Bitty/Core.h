#pragma once

#ifdef BITTY_PLATFORM_WINDOWS
	#ifdef BITTY_BUILD_DLL
		#define BITTY_API __declspec(dllexport)
	#else
		#define BITTY_API __declspec(dllimport)
	#endif
#else
	#error Bitty only support Windows
#endif