#include "bittypch.h"
#include "Application.h"
#include "Window.h"
#include "WindowProps.h"

namespace Bitty {
	application::application()
	{
		_window = std::unique_ptr<window>(window::create());
	}

	application::~application()
	{

	}

	void application::run()
	{
		while (_running)
		{
			_window->on_update();
		}
	}
}