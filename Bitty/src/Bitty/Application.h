#pragma once

#include "Core.h"
#include "Window.h"

namespace Bitty {
	class BITTY_API application
	{
	public:
		application();
		virtual ~application();

		void run();
	private:
		std::unique_ptr<window> _window;
		bool _running = true;
	};

	/// <summary>
	/// To be defined in client
	/// </summary>
	/// <returns></returns>
	application* create_application();
}