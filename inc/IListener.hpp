#ifndef SOUNDBOARD_LISTENER_H_
#define SOUNDBOARD_LISTENER_H_

typedef void(*Handler)(int);

class IListener
{
public:
    virtual void start(Handler handler) = 0;
    virtual void stop() = 0;
    virtual int active() const = 0;
};


#endif