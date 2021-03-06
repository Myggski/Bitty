#include "bittypch.h"
#include "MouseButtonPressedEvent.h"

namespace Bitty
{
	inline mouse_button_pressed_event::mouse_button_pressed_event(int button)
		: mouse_button_event_base(button) {}

	inline std::string mouse_button_pressed_event::to_string() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressed: " << _button;
		return ss.str();
	}
}