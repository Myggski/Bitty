#include "KeyPressedEvent.h"

#include <sstream>

namespace Bitty
{
	key_pressed_event::key_pressed_event(int keycode, int repeat_count)
		: key_event_base(keycode), _repeat_count(repeat_count) {}

	inline int key_pressed_event::get_repeat_count() const { return _repeat_count; }

	std::string key_pressed_event::to_string() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << _key_code << " (" << _repeat_count << " repeats";
		return ss.str();
	}
}