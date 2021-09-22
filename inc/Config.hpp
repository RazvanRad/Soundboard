#ifndef SOUNDBOARD_CONFIG_H_
#define SOUNDBOARD_CONFIG_H_

#include <map>
#include <string>

#include <JsonParser.hpp>

class Config
{

public:
    void loadConfig(std::string &filename);

    std::string getSoundPathByButtonID(int id);
    int getButtonCount() const;
    int getProtocol() const;

private:
    ConfigData data;
};

#endif