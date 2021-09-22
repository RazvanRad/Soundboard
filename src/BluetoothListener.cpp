#include <BluetoothWrapper.h>
#include <BluetoothListener.hpp>

#include <thread>

void BluetoothListener::start(Handler handler)
{

    _active = 1;

    std::thread thr(start_socket, handler, &_active);
    thr.detach();
    bthread = std::move(thr);

}

void BluetoothListener::stop()
{

    _active = 0;

    if (bthread.joinable())
        bthread.join();
        
}

int BluetoothListener::isActive() const
{
    return _active;
}