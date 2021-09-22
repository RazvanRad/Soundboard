#include <SoundBoard.hpp>

SoundBoard::SoundBoard()
{
}

void SoundBoard::run()
{

    while (true)
    {
        //wait for input
        //handle input
    }
}

void SoundBoard::init(std::string& filename)
{
    configFile.loadConfig(filename);
    
}