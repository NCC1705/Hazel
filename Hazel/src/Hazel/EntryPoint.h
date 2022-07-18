#pragma once

#ifdef HZ_PLATFORM_WINDOWS

//a function we will define somewhere else that will return that application for us
//create application will be implemented in the client
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	//allocate it on the Heap because sandbox can be very large and we want to control the lifetime of this explicitly
	//it is literally our entire application
	//definitely want to be explicit with memory when it comes to this
	printf("Hazel Engine\n");
	auto app = Hazel::CreateApplication();

	app->Run();
	delete app;
}

#endif