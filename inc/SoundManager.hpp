#ifndef SOUNDBOARD_SOUND_MANAGER_H_
#define SOUNDBOARD_SOUND_MANAGER_H_

#include "Config.hpp"
#include "IPlayer.hpp"
#include "MicrophonePlayer.hpp"
#include "SpeakerPlayer.hpp"
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>

class SoundManager
{

   static std::vector<IPlayer *> players;

public:
   void init(Config conf);
   static void playSound(int index);
};
#endif
