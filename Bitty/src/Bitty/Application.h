#pragma once

#include "Core.h"

namespace Bitty {
	class BITTY_API application
	{
	public:
		application();
		virtual ~application();

		void run();
	};

	/// <summary>
	/// To be defined in client
	/// </summary>
	/// <returns></returns>
	application* create_application();
}