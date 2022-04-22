#include "bittypch.h"
#include "WindowResizeEvent.h"

inline Bitty::window_resize_event::window_resize_event(uint32_t width, uint32_t height)
	: _width(width), _height(height) {}

inline uint32_t Bitty::window_resize_event::get_width() const { return _width; }

inline uint32_t Bitty::window_resize_event::get_height() const { return _height; }

inline std::string Bitty::window_resize_event::to_string() const
{
	std::stringstream ss;
	ss << "WindowResize: " << _width << ", " << _height;
	return ss.str();
}
