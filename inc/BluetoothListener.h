#ifndef SOUNDBOARD_BLUETOOTH_LISTENER
#define SOUNDBOARD_BLUETOOTH_LISTENER

#include <Listener.h>
#include <vector>
#include <thread>

class BluetoothListener : public Listener
{
private:
    std::thread bthread;
    int _active;
public:
    void start(Handler handler);
    void stop();
    bool active() const
    {
        return active;
    }
};

#endif