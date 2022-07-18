
#include <Hazel.h>//or
//#include "Hazel.h"//compiler include path

//namespace Hazel {
//
//	__declspec(dllimport) void Print();
//}

class Sandbox :public Hazel::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

//int main() 
//{
//	//Hazel::Print();
//	//allocate it on the Heap because sandbox can be very large and we want to control the lifetime of this explicitly
//	//it is literally our entire application
//	//definitely want to be explicit with memory when it comes to this
//	Sandbox* sandbox = new Sandbox();	
//	sandbox->Run();
//	delete sandbox;
//}

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}