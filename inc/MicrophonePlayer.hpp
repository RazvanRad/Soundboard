#ifndef SOUNDBOARD_MICROPHONE_PLAYER_H_
#define SOUNDBOARD_MICROPHONE_PLAYER_H_

#include <IPlayer.hpp>
#include <iostream>

/**
 * @brief Class for microphone device
 * 
 */
class MicrophonePlayer : public IPlayer
{
public:
    /**
     * @brief Play sound
     * 
     * @param index - wich sound we want to play
     */
    virtual void playSound(int index)
    {
        std::cout << "Se trimite prin microfon sunetul " << index << std::endl;
    }

private:
};
#endif
