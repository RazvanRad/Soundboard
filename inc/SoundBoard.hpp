#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include <chrono>
#include <thread>

#include <Config.hpp>
#include <SoundManager.hpp>

class SoundBoard
{
public:
    SoundBoard();

    void init(std::string &file);
    void run();

private:
    Config configFile;
    SoundManager audioManager;
};

#endif