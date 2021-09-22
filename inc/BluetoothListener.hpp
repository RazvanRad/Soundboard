#ifndef SOUNDBOARD_BLUETOOTH_LISTENER
#define SOUNDBOARD_BLUETOOTH_LISTENER

#include <IListener.hpp>

#include <thread>
#include <vector>

class BluetoothListener : public IListener
{
private:
    std::thread bthread;
    int _active;
public:
    void start(Handler handler);
    void stop();
    int isActive() const;
};

#endif