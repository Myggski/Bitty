#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API window_close_event : public event_base
	{
	public:
		window_close_event();

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}