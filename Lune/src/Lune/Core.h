#pragma once

#ifdef LN_PLATFORM_WINDOWS
	#ifdef LN_BUILD_DLL
		#define LUNE_API __declspec(dllexport)
	#else
		#define LUNE_API __declspec(dllimport)
	#endif
#else
	#error Lune only supports Windows!
#endif
