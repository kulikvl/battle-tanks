#include "Log.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

bool Log::isDebugMode      = false;

const string errorPrefix   = "Error:   ";
const string warningPrefix = "Warning: ";
const string debugPrefix   = "Debug:   ";

void Log::error(const string& msg)
{
    std::cerr << errorPrefix << msg << std::endl;
}

void Log::warning(const string& msg)
{
    std::cerr << warningPrefix << msg << std::endl;
}

void Log::log(const string& msg)
{
    std::cout << msg << std::endl;
}

void Log::log_raw(const string& msg)
{
    std::cout <<  msg ;
}

void Log::debug(const string& msg)
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
