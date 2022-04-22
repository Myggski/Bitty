#include "bittypch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bitty
{
	std::shared_ptr<spdlog::logger> log::core_logger;
	std::shared_ptr<spdlog::logger> log::client_logger;

	void log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		core_logger = spdlog::stdout_color_mt("BITTY");
		core_logger->set_level(spdlog::level::trace);

		client_logger = spdlog::stdout_color_mt("APP");
		client_logger->set_level(spdlog::level::trace);
	}
}