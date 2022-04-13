#pragma once

#include "../EventBase.h"

namespace Bitty 
{
	class BITTY_API key_event_base : public event_base
	{
	public:
		inline int get_key_code() const;

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		key_event_base(int key_code);

		int _key_code{};
	};
}