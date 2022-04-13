#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API app_tick_event : public event_base
	{
	public:
		app_tick_event();

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}