#pragma once
#include "Application.h"

#ifdef BITTY_PLATFORM_WINDOWS

extern Bitty::application* Bitty::create_application();

int main(int argc, char** argv)
{
	auto app = Bitty::create_application();
	app->run();
	delete app;
}

#endif