#pragma once
#include "Application.h"

#ifdef BITTY_PLATFORM_WINDOWS

extern Bitty::Application* Bitty::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Bitty::CreateApplication();
	app->Run();
	delete app;
}

#endif