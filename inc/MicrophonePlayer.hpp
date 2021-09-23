#ifndef SOUNDBOARD_MICROPHONE_PLAYER_H_
#define SOUNDBOARD_MICROPHONE_PLAYER_H_

#include <IPlayer.hpp>
#include <iostream>
class MicrophonePlayer : public IPlayer
{
public:
    virtual void playSound(int index)
    {
        std::cout << "Se trimite prin microfon sunetul " << index << std::endl;
    }

private:
};
#endif
