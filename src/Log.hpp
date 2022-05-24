#ifndef Log_hpp
#define Log_hpp

#include <iostream>
#include <fstream>
#include <string>

/// \brief Stores information on standard output streams or files.
///
/// With this class you can log different levels of information.
/// Currently we have _Error_, _Warning_, _Debug_ and _normal_ logs.
/// Each get printed with it's prefix.
///
class Log
{
private:
    static bool isDebugMode;     ///< Tells if we're on debug mode.

public:
    /// Logs *msg* with prefix "Error: ".
    ///
    /// @note By default logs to _stderr_.
    static void error(std::string msg);

    /// Logs *msg* with prefix "Warning: ".
    ///
    /// @note By default logs to _stderr_.
    static void warning(std::string msg);

    /// Logs *msg*.
    ///
    /// @note By default logs to _stdout_.
    static void log(std::string msg);

    /// Logs `msg` without end of line.
    static void log_raw(std::string msg);

    /// Logs *msg* with prefis "Debug: ".
    ///
    /// @note Only gets logged if debug mode is on.
    /// @note By default logs to _stdout_.
    static void debug(std::string msg);

    /// Turns debug on/off.
    /// This tells if all debug messages will be ignored.
    ///
    /// @note By default it is turned off.
    static void debugMode(bool option);

};

#endif /* Log_hpp */
