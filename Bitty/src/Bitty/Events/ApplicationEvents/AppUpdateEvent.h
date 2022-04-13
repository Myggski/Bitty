#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API app_update_event : public event_base
	{
	public:
		app_update_event();

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}