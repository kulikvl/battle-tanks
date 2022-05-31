#ifndef Log_hpp
#define Log_hpp

#include <string>

using namespace std;

/// \brief Stores information on standard output streams or files.
///
/// With this class you can log different levels of information.
/// Currently we have Error, Warning, Debug and normal logs.
/// Each get printed with it's prefix.
///
class Log
{
private:
    static bool isDebugMode;

public:
    /// Logs *msg* with prefix "Error: ".
    ///
    /// @note By default logs to _stderr_.
    static void error(const string& msg);

    /// Logs *msg* with prefix "Warning: ".
    ///
    /// @note By default logs to _stderr_.
    static void warning(const string& msg);

    /// Logs *msg*.
    ///
    /// @note By default logs to _stdout_.
    static void log(const string& msg);

    /// Logs `msg` without end of line.
    static void log_raw(const string& msg);

    /// Logs *msg* with prefis "Debug: ".
    ///
    /// @note Only gets logged if debug mode is on.
    /// @note By default logs to _stdout_.
    static void debug(const string& msg);

    /// Turns debug on/off.
    /// This tells if all debug messages will be ignored.
    ///
    /// @note By default it is turned off.
    static void debugMode(bool option);

};

#endif /* Log_hpp */
