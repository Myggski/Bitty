#include "MouseMovedEvent.h"

namespace Bitty
{
	inline mouse_moved_event::mouse_moved_event(float x, float y)
		: _mouse_x(x), _mouse_y(y) {}

	inline float mouse_moved_event::get_x() const { return _mouse_x; }
	inline float mouse_moved_event::get_y() const { return _mouse_y; }
	inline std::string mouse_moved_event::to_string() const
	{
		std::stringstream ss;
		ss << "MouseMoveEvent: " << _mouse_x << ", " << _mouse_y;
		return ss.str();
	}
}
