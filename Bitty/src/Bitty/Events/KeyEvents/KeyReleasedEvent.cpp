#include "KeyReleasedEvent.h"

#include <sstream>

namespace Bitty
{
	inline key_released_event::key_released_event(int key_code)
		: key_event_base(key_code) {}

	inline std::string key_released_event::to_string() const
	{
		std::stringstream ss;
		ss << "KeyReleased: " << _key_code;
		return ss.str();
	}
}