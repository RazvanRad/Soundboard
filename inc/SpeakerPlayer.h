#ifndef SPEAKERPLAYER_H_
#define SPEAKERPLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "IPlayer.h"
#include "jsonParser.h"

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
    SpeakerPlayer()
    {
    }

    ~SpeakerPlayer()
    {
        SDL_Quit();
    }

    void init(const std::string &path)
    {
        JsonParser parser(path);

        SDL_Init(SDL_INIT_AUDIO);

        if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS) != 0)
        {
            exit(-1);
        }

        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
            Mix_Chunk *tmpChunck = Mix_LoadWAV(parser.getSoundPathByButtonID(i).c_str());

            if (tmpChunck != nullptr)
            {
                m_sounds.push_back(tmpChunck);
            }
        }
    }

    Mix_Chunk *getSoundById(int index)
    {
        try
        {
            return m_sounds[index];
        }
        catch (...)
        {
            return nullptr;
        }
    }

    virtual void playSound(int index)
    {
        if (getSoundById(index) != nullptr)
            Mix_PlayChannel(1, getSoundById(index), 0);
    }
};

#endif
