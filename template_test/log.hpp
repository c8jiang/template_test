#pragma once

template<typename T>
class Singleton : private T
{
private:
    Singleton();
    ~Singleton();

public:
    static T &instance();
};

template<typename T>
inline Singleton<T>::Singleton()
{

}

template<typename T>
inline Singleton<T>::~Singleton()
{

}

template<typename T>
T& Singleton<T>::instance()
{
    static Singleton<T> s_oT;
    return s_oT;
}

#include "spdlog\spdlog.h"
#include <filesystem>

namespace fs = std::filesystem;

class LogHelper
{
public:
    LogHelper()
    {        
		make_log_dir();
        _logger = spdlog::rotating_logger_mt("_logger", "logs/log.txt", 1024 * 1024 * 1, 1);

        _logger->set_level(spdlog::level::debug);
        _logger->flush_on(spdlog::level::err);        
    }
    ~LogHelper()
    {
        spdlog::drop_all();
    }

    auto get_logger()
    {
        return _logger;
    }

private:
    void make_log_dir()
    {
        fs::path cur_path = fs::current_path();
        auto log_path = cur_path / "logs";

        if (!fs::exists(log_path))
            fs::create_directory(log_path);
    }

private:
    std::shared_ptr<spdlog::logger> _logger;
};

#define suffix(msg)                                                                                                                        \
    std::string(msg)                                                                                                                       \
        .append(" -")                                                                                                                      \
        .append(__FILE__)                                                                                                                  \
        .append(":")                                                                                                                       \
        .append(__func__)                                                                                                                  \
        .append("() #")                                                                                                                    \
        .append(std::to_string(__LINE__))                                                                                                  \
        .append(".")                                                                                                                       \
        .c_str()

#define LOG_DEBUG(msg, ...) Singleton<LogHelper>::instance().get_logger()->debug(suffix(msg), __VA_ARGS__)
#define LOG_INFO(...) Singleton<LogHelper>::instance().get_logger()->info(__VA_ARGS__)
#define LOG_ERROR(...) Singleton<LogHelper>::instance().get_logger()->error(__VA_ARGS__)