#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API mouse_button_event_base : public event_base
	{
	public:
		inline int get_mouse_button() const;

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		mouse_button_event_base(int button);

		int _button{};
	};
}