#ifndef SOUNDBOARD_LISTENER
#define SOUNDBOARD_LISTENER

typedef void(*Handler)(int);

class Listener
{
public:
    virtual void start(Handler handler) = 0;
    virtual void stop() = 0;
};

#endif