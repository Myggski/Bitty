#pragma once

#include "../EventBase.h"

#include <sstream>

namespace Bitty
{
	class BITTY_API mouse_scrolled_event : public event_base
	{
	public:
		mouse_scrolled_event(float x_offset, float y_offset);

		inline float get_x_offset() const;
		inline float get_y_offset() const;
		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _x_offset{};
		float _y_offset{};
	};
}
