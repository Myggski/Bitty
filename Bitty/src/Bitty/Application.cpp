#include "Application.h"

#include "Bitty/Events/ApplicationEvent.h"
#include "Bitty/Log.h"

namespace Bitty {
	Application::Application() 
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BITTY_TRACE(e.ToString());
	}
}