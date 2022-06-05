#ifndef Config_hpp
#define Config_hpp

#include <map>
#include <string>

#define COMMENT_CHAR '#'

using namespace std;

/// @brief Handles global game customizations and settings based on a config file. Static class.
///
/// @note It parses files with the INI format. Here's an example:
///
///     # Comments start with '#'
///
///     key       = value
///     other_key = 22
///     some_val  = true
///
class Config
{
public:
    /// Opens, loads and parses configuration file `filename`.
    static void load(string filename);

    /// Tells if the configuration has `key` defined.
    static bool has(string key);

    /// Returns the value defined with `key`.
    ///
    /// @return Empty string if value is not found.
    ///
    static string get(string key);

    /// Returns the boolean value associated with `key`.
    ///
    /// @note It recognizes "true" and "yes" as valid
    ///       strings. Everything else is false.
    ///
    static bool getBool(string key, bool defaultVal);

    /// Returns the int value associated with `key`.
    static int getInt(string key, int defaultVal);
    
    /// Returns the float value associated with `key`.
    static int getFloat(string key, float defaultVal);
    
private:
    /// Actual internal map of std::string keys to values.
    static map<string, string> config;
    
};

#endif /* Config_hpp */
