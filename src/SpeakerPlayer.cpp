#include <SpeakerPlayer.hpp>

SpeakerPlayer::SpeakerPlayer()
{
}

SpeakerPlayer::~SpeakerPlayer()
{
    SDL_Quit();
}

void SpeakerPlayer::init(Config conf)
{
    SDL_Init(SDL_INIT_AUDIO);

    if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS) != 0)
    {
        exit(-1);
    }

    for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        Mix_Chunk *tmpChunck = Mix_LoadWAV(conf.getSoundPathByButtonID(i+1).c_str());
        if (tmpChunck != nullptr)
        {
            m_sounds.push_back(tmpChunck);
        }
    }
}

Mix_Chunk *SpeakerPlayer::getSoundById(int index)
{
    try
    {
        return m_sounds.at(index);
    }
    catch (...)
    {
        return nullptr;
    }
}

void SpeakerPlayer::playSound(int index)
{
    if (getSoundById(index) != nullptr){
        std::cout << "Se trimite prin speaker sunetul " << index << std::endl;
        Mix_PlayChannel(1, getSoundById(index), 0);
    }
}