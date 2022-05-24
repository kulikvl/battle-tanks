#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include "Config.hpp"
#include "Utils.hpp"
#include "Log.hpp"

using namespace std;

map<string, string> Config::config;

void Config::load(string filename)
{
    Config::config.clear();

    ifstream file(filename);

    if (!file.is_open())
    {
        Log::error("Config::load: Couldn't open '" + filename + "'");
        throw runtime_error("Failed to open a config file");
    }

    while (!file.eof())
    {
        string line;
        getline(file, line, '\n');

        if (line.empty() || line[0] == COMMENT_CHAR) continue;
            
        size_t pos = line.find("=");
        if (pos == string::npos) throw runtime_error("Wrong format config file");
        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);
        key.erase(remove_if(key.begin(), key.end(), [](unsigned char x) { return std::isspace(x); }), key.end());
        value.erase(remove_if(value.begin(), value.end(), [](unsigned char x) { return std::isspace(x); }), value.end());
        
        if (Config::has(key))
        {
            Log::warning("Config::load: Existing key '" +
                         key +
                         "' that maps to '" +
                         value +
                         "'");
            continue;
        }

        Config::config.insert(pair<string,string>(key, value));
    }
}

bool Config::has(string key)
{
    map<string, string>::iterator it = Config::config.find(key);
    return (it != Config::config.end());
}

string Config::get(string key)
{
    map<string, string>::iterator it = Config::config.find(key);

    if (it == Config::config.end())
    {
        Log::error("Config::get: Tried to get unexisting key '" + key + "'");
        return "";
    }
    
    return (*it).second;
}

bool Config::getBool(string key, bool defaultVal)
{
    string value = Config::get(key);
    if (value.empty())
        return defaultVal;

    if ((value.compare("true") == 0) || (value.compare("yes")  == 0))
        return true;

    return false;
}

int Config::getInt(string key, int defaultVal)
{
    std::string value = Config::get(key);
    if (value.empty()) return defaultVal;
    return stoi(value);
}

int Config::getFloat(string key, float defaultVal)
{
    std::string value = Config::get(key);
    if (value.empty()) return defaultVal;
    return stof(value);
}
