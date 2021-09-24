#ifndef SOUNDBOARD_SPEAKER_PLAYER_H_
#define SOUNDBOARD_SPEAKER_PLAYER_H_

#include <iostream>
#include <string>
#include <vector>

#include <IPlayer.hpp>
#include <Config.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define AUDIO_RATE 22050
#define AUDIO_FORMAT AUDIO_S16SYS
#define AUDIO_CHANNELS 2
#define AUDIO_BUFFERS 4096
#define NUMBER_OF_BUTTONS 3

/**
 * @brief Class for speaker device
 * 
 */
class SpeakerPlayer : public IPlayer
{
private:
    std::vector<Mix_Chunk *> m_sounds; // store sounds that we want to play

public:
    /**
     * @brief Construct a new Speaker Player object
     * 
     */
    SpeakerPlayer();

    /**
     * @brief Destroy the Speaker Player object
     * 
     */
    ~SpeakerPlayer();

    /**
     * @brief Populate vector of sounds
     * 
     * @param conf - get data from config.json
     */
    void init(Config conf);

    /**
     * @brief Get the Sound By Id object
     * 
     * @param index - which sound we want to get
     * @return Mix_Chunk* - return the sound we want to play
     */
    Mix_Chunk *getSoundById(int index);

    /**
     * @brief Play sound
     * 
     * @param index - wich sound we want to play
     */
    virtual void playSound(int index);
};

#endif
