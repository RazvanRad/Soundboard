#ifndef SOUNDBOARD_PLAYER_H
#define SOUNDBOARD_PLAYER_H

/**
 * @brief Interface for devices
 * 
 */
class IPlayer
{
public:
    /**
     * @brief Play sound
     * 
     * @param index - wich sound we want to play
     */
    virtual void playSound(int index) = 0;
};
#endif