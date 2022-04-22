#include "bittypch.h"
#include "KeyEventBase.h"

namespace Bitty
{
	key_event_base::key_event_base(int key_code)
		: _key_code(key_code) {}

	inline int key_event_base::get_key_code() const { return _key_code; }
}