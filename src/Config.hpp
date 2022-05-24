#ifndef Config_hpp
#define Config_hpp

#include <map>
#include <string>

#define COMMENT_CHAR '#'

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
    static void load(std::string filename);

    /// Tells if the configuration has `key` defined.
    static bool has(std::string key);

    /// Returns the value defined with `key`.
    ///
    /// @return Empty string if value is not found.
    ///
    static std::string get(std::string key);

    /// Returns the boolean value associated with `key`.
    ///
    /// @note It recognizes "true" and "yes" as valid
    ///       strings. Everything else is false.
    ///
    static bool getBool(std::string key, bool defaultVal);

    /// Returns the int value associated with `key`.
    ///
    static int getInt(std::string key, int defaultVal);

    
    /// Returns the float value associated with `key`.
    ///
    static int getFloat(std::string key, float defaultVal);
    

private:
    /// Actual internal map of std::string keys to values.
    static std::map<std::string, std::string> config;
};

#endif /* Config_hpp */
