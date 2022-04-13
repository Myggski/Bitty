#pragma once

#include "../EventBase.h"

namespace Bitty
{
	class BITTY_API window_resize_event : public event_base
	{
	public:
		window_resize_event(uint32_t width, uint32_t height);
		inline uint32_t get_width() const;
		inline uint32_t get_height() const;
		std::string to_string() const override;

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		uint32_t _width{};
		uint32_t _height{};
	};
}
