#include "bittypch.h"
#include "WindowProps.h"

inline Bitty::window_props::window_props(const std::string& title, unsigned int width, unsigned int height)
	: title(title), width(width), height(height) {}