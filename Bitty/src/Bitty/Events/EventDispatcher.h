#pragma once

#include <functional>

namespace Bitty
{
	class event_base;

	class event_dispatcher
	{
		template<typename T>
		using event_fn = std::function<bool(T&)>;
	public:
		event_dispatcher(Bitty::event_base& event)
			: _event(event) {}

		template<typename T>
		bool dispatch(event_fn<T> func)
		{
			if (_event.get_event_type() == T::get_static_type())
			{
				_event._handled |= func(static_cast<T&>(_event));
				return true;
			}

			return false;
		}
	private:
		Bitty::event_base& _event;
	};
}