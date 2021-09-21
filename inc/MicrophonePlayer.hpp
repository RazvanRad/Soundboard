#ifndef SOUNDBOARD_MICROPHONE_PLAYER_H_
#define SOUNDBOARD_MICROPHONE_PLAYER_H_

#include <IPlayer.hpp>

class MicrophonePlayer : public IPlayer
{
public:
    virtual void playSound(int index)
    {
    }

private:
};
#endif
