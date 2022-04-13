#include "MouseButtonEventBase.h"

namespace Bitty
{
	mouse_button_event_base::mouse_button_event_base(int button)
		: _button(button) {}

	inline int mouse_button_event_base::get_mouse_button() const { return _button; }
}