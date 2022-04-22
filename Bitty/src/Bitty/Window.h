#pragma once

#include "bittypch.h"

#include "Bitty/Core.h"
#include "Bitty/Events/EventBase.h"
#include "WindowProps.h"

namespace Bitty
{
	class BITTY_API window
	{
	public:
		using event_callback_fn = std::function<void(event_base&)>;

		virtual ~window();
		
		virtual void on_update() = 0;

		virtual uint32_t get_width() const = 0;
		virtual uint32_t get_height() const = 0;

		virtual void set_event_callback(const event_callback_fn& callback) = 0;
		virtual void set_v_sync(bool enabled) = 0;
		virtual bool is_v_sync() const = 0;

		static window* create(const window_props& props = window_props());
	};
}