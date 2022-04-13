#pragma once

#include "MouseButtonEventBase.h"

namespace Bitty
{
	class BITTY_API mouse_button_pressed_event : public mouse_button_event_base
	{
	public:
		mouse_button_pressed_event(int button);

		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
}
