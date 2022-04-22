#include "bittypch.h"
#include "WindowsWindow.h"
#include "Bitty/WindowProps.h"

namespace Bitty 
{
	static bool _GLWF_initialized{ false };

	window* window::create(const window_props& props)
	{
		return new windows_window(props);
	}

	windows_window::windows_window(const window_props& props)
	{
		init(props);
	}

	windows_window::~windows_window() 
	{
		shut_down();
	}

	void windows_window::init(const window_props& props)
	{
		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		BITTY_CORE_INFO("Creating window {0} ({1}, {2}", props.title, props.width, props.height);

		if (!_GLWF_initialized)
		{
			int success = glfwInit();
			BITTY_CORE_ASSERT(success, "Could not initalize GLFW.");

			_GLWF_initialized = true;
		}

		_window = glfwCreateWindow((int)props.width, (int)props.height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		set_v_sync(true);
	}

	void windows_window::shut_down()
	{
		glfwDestroyWindow(_window);
	}

	void windows_window::on_update()
	{
		glfwPollEvents();;
		glfwSwapBuffers(_window);
	}

	void windows_window::set_v_sync(bool enabled)
	{
		glfwSwapInterval((int)enabled);
		_data.v_sync = enabled;
	}

	bool windows_window::is_v_sync() const
	{
		return _data.v_sync;
	}
}