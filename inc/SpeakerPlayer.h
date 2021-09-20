#ifndef SPEAKERPLAYER_H_
#define SPEAKERPLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "IPlayer.h"
#include "JsonParser.h"

#define AUDIO_RATE 22050
#define AUDIO_FORMAT AUDIO_S16SYS
#define AUDIO_CHANNELS 2
#define AUDIO_BUFFERS 4096
#define NUMBER_OF_BUTTONS 3
class SpeakerPlayer : public IPlayer
{

private:
    std::vector<Mix_Chunk *> m_sounds;

public:
    SpeakerPlayer();
    ~SpeakerPlayer();
    void init(const std::string &path);
    Mix_Chunk *getSoundById(int index);
    virtual void playSound(int index);
};

#endif
