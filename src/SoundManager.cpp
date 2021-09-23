#include <SoundManager.hpp>

std::vector<IPlayer *> SoundManager::players;

void SoundManager::init(Config conf)
{
    std::vector<std::string> name_players = conf.getPlayers();
    for (int i = 0; i < name_players.size(); i++)
    {
        boost::to_lower(name_players[i]);

        if (name_players[i] == "speakerplayer")
        {
            SpeakerPlayer *spkPlayer = new SpeakerPlayer();
            spkPlayer->init(conf);
            players.push_back(spkPlayer);
        }
        else if (name_players[i] == "micplayer")
        {
            players.push_back(new MicrophonePlayer());
        }
    }
}

void SoundManager::playSound(int index)
{
    for (auto player : players)
    {
        player->playSound(index);
    }
}

