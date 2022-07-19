#pragma once

#ifdef HZ_PLATFORM_WINDOWS

//a function we will define somewhere else that will return that application for us
//create application will be implemented in the client
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	Hazel::Log::GetCoreLogger()->warn("Initialized Core Log!");
	HZ_CORE_WARN("Initialized Core Log!");
	int a = 5;
	Hazel::Log::GetClientLogger()->info("Initialized Client Log! Var={0}", a);
	HZ_CORE_INFO("Initialized Client Log!");

	//allocate it on the Heap because sandbox can be very large and we want to control the lifetime of this explicitly
	//it is literally our entire application
	//definitely want to be explicit with memory when it comes to this
	//printf("Hazel Engine\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif

/*
	If only header files are modified, we dont need to copy dll from bin\debug-x64 Hazel to Sandbox
*/