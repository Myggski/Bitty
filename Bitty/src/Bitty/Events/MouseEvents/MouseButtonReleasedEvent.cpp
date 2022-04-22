#include "bittypch.h"
#include "MouseButtonReleasedEvent.h"

namespace Bitty
{
	inline mouse_button_released_event::mouse_button_released_event(int button)
		: mouse_button_event_base(button) {}

	inline std::string mouse_button_released_event::to_string() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleased: " << _button;
		return ss.str();
	}
}