#include "EventBase.h"

namespace Bitty
{
	inline std::string event_base::to_string() const { return get_name(); }
	inline bool event_base::is_in_category(EventCategory category)
	{
		return get_category_flags() & category;
	}
}