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

#ifdef LN_DEBUG
	#define LN_ENABLE_ASSERTS
#endif

#ifdef LN_ENABLE_ASSERTS
	#define LN_ASSERT(x, ...) { if(!(x)) { LN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LN_CORE_ASSERT(x, ...) { if(!(x)) { LN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LN_ASSERT(x, ...)
	#define LN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define DISPATCH(d, e, fn) d.Dispatch<e>(BIND_EVENT_FN(fn));