#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Bitty {
	class BITTY_API log
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger;  }
		static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger;  }
	private:
		static std::shared_ptr<spdlog::logger> core_logger;
		static std::shared_ptr<spdlog::logger> client_logger;
	};
}

// Core log macros
#define BITTY_CORE_TRACE(...)::Bitty::log::get_core_logger()->trace(__VA_ARGS__)
#define BITTY_CORE_INFO(...)::Bitty::log::get_core_logger()->info(__VA_ARGS__)
#define BITTY_CORE_WARN(...)::Bitty::log::get_core_logger()->warn(__VA_ARGS__)
#define BITTY_CORE_ERROR(...)::Bitty::log::get_core_logger()->error(__VA_ARGS__)
#define BITTY_CORE_CRITICAL(...)::Bitty::log::get_core_logger()->critical(__VA_ARGS__)

// Client log macros
#define BITTY_TRACE(...)::Bitty::log::get_client_logger()->trace(__VA_ARGS__)
#define BITTY_INFO(...)::Bitty::log::get_client_logger()->info(__VA_ARGS__)
#define BITTY_WARN(...)::Bitty::log::get_client_logger()->warn(__VA_ARGS__)
#define BITTY_ERROR(...)::Bitty::log::get_client_logger()->error(__VA_ARGS__)
#define BITTY_CRITICAL(...)::Bitty::log::get_client_logger()->critical(__VA_ARGS__)