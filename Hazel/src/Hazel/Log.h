#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel {

	class HAZEL_API Log
	{
	
	public:
		/*Log();
		~Log();*/
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}
// Core log macros
#define HZ_CORE_TRACE(...)		::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)			::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)			::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)			::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)			::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)			::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)

//__VA_ARGS__ = forwarding our variable arguments that we had in our macro to our actual function

//if dist build
//#define HZ_CORE_INFO//define this to be nothing



/*			STATIC VARIABLE
https://pencilprogrammer.com/cpp-tutorials/static-variable-cplusplus/

When the static keyword preceded the declaration of a variable, that variable becomes a static variable.

Syntax:

static <type> <variable_name>;
A static keyword serves a different purpose depending on where it has been declared.

If it is declared inside of a class, all instances of the class (i.e. objects) will share the same copy of the variable, and we can access it without any object by class name outside the class.

If it is declared inside of a function then its value is preserved between successive calls for the lifetime of the program, but it cannot be accessd outside the scope or function in which it is declared.
*/


/*			STATIC FUNCTION
https://pencilprogrammer.com/cpp-tutorials/static-function-cplusplus/

A function that is declared static using the ‘static‘ keyword becomes a static function in C++.

Syntax of the Static Function:

static <return_type> <function_name>(<arguments>){
	//code
}

When a function inside a class is declared as static, it can be accessed outside the class using the class name and scope resolution operator (::), without creating any object.

A static member method has access only to the static members of the class, we can not call any non-static functions inside it.

All objects in the class share the same copy of the static function. It is useful in manipulating global static variables, which are again shared by all objects.
Since the static function is not bounded by the object of the class, it does not has access to the this keyword.
*/