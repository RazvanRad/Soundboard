#ifndef SOUNDBOARD_BLUETOOTH_LISTENER
#define SOUNDBOARD_BLUETOOTH_LISTENER

#include <IListener.hpp>
#include <vector>
#include <thread>

class BluetoothListener : public IListener
{
private:
    std::thread bthread;
    int _active;
public:
    void start(Handler handler);
    void stop();
    int active() const
    {
        return _active;
    }
};

#endif