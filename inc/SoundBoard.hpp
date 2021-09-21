#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include <Config.hpp>
#include <SoundManager.hpp>
#include <JsonParser.hpp>
#include <map>

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