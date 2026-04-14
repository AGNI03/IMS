#pragma once
#include <string>

class EnvLoader
{
public:
    static void load(const std::string& filename);

private:
    static std::string trim(const std::string& str);
    static void setEnv(const std::string& key, const std::string& value);
};

