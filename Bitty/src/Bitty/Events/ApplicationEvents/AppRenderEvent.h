#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API app_render_event : public event_base
	{
	public:
		app_render_event();

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
