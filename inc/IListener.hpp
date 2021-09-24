#ifndef SOUNDBOARD_LISTENER_H_
#define SOUNDBOARD_LISTENER_H_

typedef void(*Handler)(int);

class IListener
{
public:
    virtual void start(Handler handler) = 0;
    virtual void stop() = 0;
    virtual int init() = 0;
    virtual int isActive() const = 0;
};


#endif