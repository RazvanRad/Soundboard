#ifndef MICROPHONEPLAYER_H_
#define MICROPHONEPLAYER_H_

#include "IPlayer.h"

class MicrophonePlayer : public IPlayer
{
public:
    virtual int playSound(int index)
    {
        return 0;
    }
};
#endif