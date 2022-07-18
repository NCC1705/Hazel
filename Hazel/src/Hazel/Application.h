#pragma once

#include "Core.h"

namespace Hazel {
	//class __declspec(dllexport) Application//becomes:
	class HAZEL_API Application
	{

	public:
		Application();
		virtual ~Application();//application will be inherited by the sandbox application

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}