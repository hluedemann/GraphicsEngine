#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>

namespace engine {

class Log
{
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger> getCoreLogger() { return coreLogger_; }
    inline static std::shared_ptr<spdlog::logger> getClientLogger() { return clientLogger_; }

private:
    static std::shared_ptr<spdlog::logger> coreLogger_;
    static std::shared_ptr<spdlog::logger> clientLogger_;
};

}


// Core log macros

#define E_CORE_ERROR(...)   ::engine::Log::getCoreLogger()->error(__VA_ARGS__)
#define E_CORE_WARN(...)    ::engine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define E_CORE_INFO(...)    ::engine::Log::getCoreLogger()->info(__VA_ARGS__)
#define E_CORE_TRACE(...)   ::engine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define E_CORE_FATAL(...)   ::engine::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros

#define E_ERROR(...)        ::engine::Log::getClientLogger()->error(__VA_ARGS__)
#define E_WARN(...)         ::engine::Log::getClientLogger()->warn(__VA_ARGS__)
#define E_INFO(...)         ::engine::Log::getClientLogger()->info(__VA_ARGS__)
#define E_TRACE(...)        ::engine::Log::getClientLogger()->trace(__VA_ARGS__)
#define E_FATAL(...)        ::engine::Log::getClientLogger()->fatal(__VA_ARGS__)



#endif // LOG_H
