#include "logger.hpp"

std::string Logger::get_timestamp()
{
  auto t_start = std::chrono::system_clock::now();
  std::string timestamp = std::format("[{0:%H:%M:%S}]", t_start);
  return timestamp;
}
std::string Logger::format_for(log_type type, std::string msg)
{
  std::string fmtd_string = get_timestamp();
  std::string fmtd_name = "[" + name + "]";
  if (type == T_ERROR_MSG)
    fmtd_string += "[ERROR]" + fmtd_name;
  else if (type == T_INFO_MSG)
    fmtd_string += "[INFO]" + fmtd_name;
  else if (type == T_DEBUG_MSG)
    fmtd_string += "[DEBUG]" + fmtd_name;

  return fmtd_string + " " + msg;
}

void Logger::error(std::string msg)
{
  perror(format_for(T_ERROR_MSG, msg).c_str());
  exit(1);
}

void Logger::info(std::string msg)
{
  std::cout << format_for(T_INFO_MSG, msg) << std::endl;
}

void Logger::debug(std::string msg)
{
  if (lvl == L_DEBUG)
    std::cout << format_for(T_DEBUG_MSG, msg) << std::endl;
}
void Logger::set_name(std::string new_name)
{
  if (new_name == name)
    return;

  name = new_name;
}