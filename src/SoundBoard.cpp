#include <SoundBoard.hpp>

SoundBoard::SoundBoard() {}

void SoundBoard::run()
{

    while (true)
    {
        //wait for input from the raspberry pi
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        //handle input
    }
}

void SoundBoard::init(std::string &filename)
{
    configFile.loadConfig(filename);
}