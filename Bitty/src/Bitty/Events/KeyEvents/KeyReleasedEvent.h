#pragma once

#include "KeyEventBase.h"

namespace Bitty
{
	class BITTY_API key_released_event : public key_event_base
	{
	public:
		key_released_event(int keycode);

		std::string to_string() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};
}