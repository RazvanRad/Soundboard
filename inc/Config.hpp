#ifndef SOUNDBOARD_CONFIG_H_
#define SOUNDBOARD_CONFIG_H_

#include <map>
#include <string>

class Config
{

public:
    void loadConfig(std::map<int,std::string> pathById);

private:
    std::map<int, std::string> pathById;
};

#endif
