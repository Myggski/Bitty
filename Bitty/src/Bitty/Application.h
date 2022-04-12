#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Bitty {
	class BITTY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/// <summary>
	/// To be defined in client
	/// </summary>
	/// <returns></returns>
	Application* CreateApplication();
}