#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include "Config.h"
#include "SoundManager.h"
#include <map>

class SoundBoard
{
public:
    SoundBoard();
    void initUsingConfig(std::map<int,std::string> pathById);
    
private:
    void run();
    Config configFile;
    SoundManager audioManager;
};

#endif