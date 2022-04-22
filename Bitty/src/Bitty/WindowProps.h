#pragma once

namespace Bitty
{
	struct BITTY_API window_props
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		window_props(const std::string& title = "Bitty Engine", unsigned int width = 1280, unsigned int height = 720);
	};
}