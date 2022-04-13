#pragma once

#include "../EventBase.h"

#include <sstream>

namespace Bitty
{
	class BITTY_API mouse_moved_event : public event_base
	{
	public:
		mouse_moved_event(float x, float y);

		inline float get_x() const;
		inline float get_y() const;
		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _mouse_x{};
		float _mouse_y{};
	};
}