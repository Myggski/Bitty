#pragma once

#include "Bitty/Window.h"
#include "Bitty/WindowProps.h"

#include <GLFW/glfw3.h>

namespace Bitty {
	class windows_window : public window
	{
	public:
		windows_window(const window_props& props);
		virtual ~windows_window();

		void on_update() override;

		inline uint32_t get_width() const override { return _data.width; }
		inline uint32_t get_height() const override { return _data.height; }

		inline void set_event_callback(const event_callback_fn& callback) override { _data.event_callback = callback; }
		void set_v_sync(bool enabled) override;
		bool is_v_sync() const override;
		private:
			virtual void init(const window_props& props);
			virtual void shut_down();
		private:
			GLFWwindow* _window;

			struct window_data
			{
				std::string title;
				uint32_t width;
				uint32_t height;
				bool v_sync;

				event_callback_fn event_callback;
			};

			window_data _data;
	};
}


