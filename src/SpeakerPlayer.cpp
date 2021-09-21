#include <SpeakerPlayer.hpp>

SpeakerPlayer::SpeakerPlayer()
{
}

SpeakerPlayer::~SpeakerPlayer()
{
    SDL_Quit();
}

void SpeakerPlayer::init(const std::string &path)
{
    JsonParser parser(path);

    SDL_Init(SDL_INIT_AUDIO);

    if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS) != 0)
    {
        exit(-1);
    }

    for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        Mix_Chunk *tmpChunck = Mix_LoadWAV(parser.getSoundPathByButtonID(i).c_str());

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
        return m_sounds[index];
    }
    catch (...)
    {
        return nullptr;
    }
}

void SpeakerPlayer::playSound(int index)
{
    if (getSoundById(index) != nullptr)
        Mix_PlayChannel(1, getSoundById(index), 0);
}