#pragma once

namespace Bitty
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	#define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::##type; }\
					virtual EventType get_event_type() const override { return get_static_type(); }\
					virtual const char* get_name() const override { return #type; }
}
