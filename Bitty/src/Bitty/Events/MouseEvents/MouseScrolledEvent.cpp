#include "bittypch.h"
#include "MouseScrolledEvent.h"

namespace Bitty
{
	inline mouse_scrolled_event::mouse_scrolled_event(float x_offset, float y_offset)
		: _x_offset(x_offset), _y_offset(y_offset) {}

	inline float mouse_scrolled_event::get_x_offset() const { return _x_offset; }
	inline float mouse_scrolled_event::get_y_offset() const { return _y_offset; }
	inline std::string mouse_scrolled_event::to_string() const
	{
		std::stringstream ss;
		ss << "MouseScrolled: " << _x_offset << ", " << _y_offset;
		return ss.str();
	}
}