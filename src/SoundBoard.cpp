#include "SoundBoard.h"

SoundBoard::SoundBoard()
{
}

void SoundBoard::initUsingConfig(std::map<int,std::string> pathById)
{
    this->configFile.loadConfig(pathById);
    //pass everything needed to the config
 
}

void SoundBoard::run()
{
    while (true)
    {
    }
}