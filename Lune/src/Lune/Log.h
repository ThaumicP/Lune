#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lune
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define LN_CORE_CRITICAL(...) ::Lune::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define LN_CORE_ERROR(...) ::Lune::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LN_CORE_WARN(...) ::Lune::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LN_CORE_INFO(...) ::Lune::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LN_CORE_TRACE(...) ::Lune::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log Macros
#define LN_CRITICAL(...) ::Lune::Log::GetClientLogger()->critical(__VA_ARGS__)
#define LN_ERROR(...) ::Lune::Log::GetClientLogger()->error(__VA_ARGS__)
#define LN_WARN(...) ::Lune::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LN_INFO(...) ::Lune::Log::GetClientLogger()->info(__VA_ARGS__)
#define LN_TRACE(...) ::Lune::Log::GetClientLogger()->trace(__VA_ARGS__)
