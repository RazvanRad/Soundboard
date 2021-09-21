#ifndef SOUNDBOARD_PLAYER_H
#define SOUNDBOARD_PLAYER_H

class IPlayer{

public:
    virtual void playSound(int index) = 0;
private:
};
#endif