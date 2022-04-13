#pragma once

#include "KeyEventBase.h"

namespace Bitty
{
	class BITTY_API key_pressed_event : public key_event_base
	{
	public:
		key_pressed_event(int keycode, int repeatCount);

		inline int get_repeat_count() const;
		std::string to_string() const override;

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeat_count{};
	};
}
