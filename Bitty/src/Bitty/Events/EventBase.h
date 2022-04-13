#pragma once

#include "Bitty/Core.h"
#include "EventType.h"
#include "EventCategory.h"
#include "EventDispatcher.h"

#include <string>
#include "spdlog/fmt/ostr.h"

namespace Bitty
{
	class BITTY_API event_base
	{
		friend class event_dispatcher;
	public:
		virtual EventType get_event_type() const = 0;
		virtual const char* get_name() const = 0;
		virtual int get_category_flags() const = 0;
		virtual std::string to_string() const;
		inline bool is_in_category(EventCategory category);
		friend std::ostream& operator<<(std::ostream& os, const event_base& e)
		{
			return os << e.to_string();
		}
	protected:
		bool _handled{ false };
	};
}