#ifndef SOUNDBOARD_SOUND_MANAGER_H_
#define SOUNDBOARD_SOUND_MANAGER_H_

#include "Config.hpp"
#include "IPlayer.hpp"
#include "MicrophonePlayer.hpp"
#include "SpeakerPlayer.hpp"
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
/**
 * @brief Class used for store devices and play sound on them. 
 * 
 */
class SoundManager
{
private:
   static std::vector<IPlayer *> players; // store devices

public:
   /**
    * @brief Initialize devices
    * 
    * @param conf - get data from config.json
    */
   void init(Config conf);

   /**
    * @brief Play sound on all devices from stored in players
    * 
    * @param index - wich sound we want to play
    */
   static void playSound(int index);
};
#endif
