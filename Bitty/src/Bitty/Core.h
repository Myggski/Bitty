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

#ifdef BITTY_ENABLE_ASSERTS
	#define	BITTY_ASSERT(x, ...) { if (!(x))} { BITTY_CORE("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define	BITTY_CORE_ASSERT(x, ...) { if (!(x))} { BITTY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BITTY_ASSERT(x, ...)
	#define BITTY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
