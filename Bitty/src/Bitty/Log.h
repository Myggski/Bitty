#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Bitty {
	class BITTY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define BITTY_CORE_TRACE(...)::Bitty::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BITTY_CORE_INFO(...)::Bitty::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BITTY_CORE_WARN(...)::Bitty::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BITTY_CORE_ERROR(...)::Bitty::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BITTY_CORE_CRITICAL(...)::Bitty::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BITTY_TRACE(...)::Bitty::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BITTY_INFO(...)::Bitty::Log::GetClientLogger()->info(__VA_ARGS__)
#define BITTY_WARN(...)::Bitty::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BITTY_ERROR(...)::Bitty::Log::GetClientLogger()->error(__VA_ARGS__)
#define BITTY_CRITICAL(...)::Bitty::Log::GetClientLogger()->critical(__VA_ARGS__)