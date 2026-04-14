#include "EnvLoader.hpp"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

std::string EnvLoader::trim(const std::string& str){
    const char* whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)return "";
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

void EnvLoader::setEnv(const std::string& key, const std::string& value){
    #ifdef _WIN32
        _putenv_s(key.c_str(), value.c_str());
    #else
        setenv(key.c_str(), value.c_str(), 1);
    #endif
}

void EnvLoader::load(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return;

    std::string line;

    while (std::getline(file, line))
    {
        line = trim(line);

        // skip empty lines
        if (line.empty())
            continue;

        // skip comments
        if (line[0] == '#')
            continue;

        // support "export KEY=value"
        if (line.rfind("export ", 0) == 0)
        {
            line = line.substr(7);
        }

        size_t eqPos = line.find('=');

        if (eqPos == std::string::npos)
            continue;

        std::string key = trim(line.substr(0, eqPos));
        std::string value = trim(line.substr(eqPos + 1));

        // remove inline comment
        size_t commentPos = value.find('#');
        if (commentPos != std::string::npos)
        {
            value = trim(value.substr(0, commentPos));
        }

        // remove quotes
        if (value.size() >= 2)
        {
            if ((value.front() == '"' && value.back() == '"') ||
                (value.front() == '\'' && value.back() == '\''))
            {
                value = value.substr(1, value.size() - 2);
            }
        }

        setEnv(key, value);
    }
}