#include "Log.hpp"
#include <sstream>

bool Log::isDebugMode           = false;

const std::string errorPrefix   = "Error:   ";
const std::string warningPrefix = "Warning: ";
const std::string debugPrefix   = "Debug:   ";

void Log::error(std::string msg)
{
    std::cerr << errorPrefix << msg << std::endl;
}
void Log::warning(std::string msg)
{
    std::cerr << warningPrefix << msg << std::endl;
}
void Log::log(std::string msg)
{
    std::cout << msg << std::endl;
}
void Log::log_raw(std::string msg)
{
    std::cout <<  msg ;
}
void Log::debug(std::string msg)
{
    if (isDebugMode)
        std::cerr << debugPrefix << msg << std::endl;
}
void Log::debugMode(bool option)
{
    if (option == false)
    {
        isDebugMode = false;
        return;
    }

    isDebugMode = true;
    Log::debug(">Debug mode activated");
}
