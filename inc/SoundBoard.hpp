#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include <Config.hpp>
#include <SoundManager.hpp>

class SoundBoard
{
public:
    SoundBoard();

    void init(std::string &file);

private:
    void run();
    Config configFile;
    SoundManager audioManager;
};

#endif