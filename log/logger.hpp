#ifndef LOG_CLASS
#define LOG_CLASS

#ifndef PP_LOG_LEVEL
#define PP_LOG_LEVEL 0
#endif

#include <string>
#include <iostream>
#include <chrono>
#include <format>

enum log_type
{
  T_ERROR_MSG,
  T_INFO_MSG,
  T_DEBUG_MSG
};

enum log_level
{
  L_CLASSIC,
  L_DEBUG
};
class Logger
{
public:
  Logger() : name("[GENERIC]"), lvl((log_level)PP_LOG_LEVEL) {}
  Logger(std::string logger_name) : name(logger_name), lvl((log_level)PP_LOG_LEVEL) {}
  Logger(std::string logger_name, log_level logging_level) : name(logger_name), lvl(logging_level) {}

  void error(std::string msg);
  void info(std::string msg);
  void debug(std::string msg);
  void set_name(std::string new_name);

private:
  std::string name;
  log_level lvl;
  std::string get_timestamp();
  std::string format_for(log_type type, std::string msg);
};

#endif