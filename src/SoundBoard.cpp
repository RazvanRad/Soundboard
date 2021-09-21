#include <SoundBoard.hpp>

SoundBoard::SoundBoard()
{
}

void SoundBoard::run()
{
    while (true)
    {
    }
}
void SoundBoard::init(std::string filename)
{
    configFile.loadConfig(filename);
}