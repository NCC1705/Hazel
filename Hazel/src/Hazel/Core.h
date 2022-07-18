#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)//active when we build the Hazel library
	#else
		#define HAZEL_API __declspec(dllimport)//active when we build the Sandbox
	#endif
#else
	#error Hazel only supports Windows!
#endif