#include <BluetoothWrapper.h>
#include <BluetoothListener.hpp>

#include <thread>

void BluetoothListener::start(Handler handler)
{
    std::thread thr(start_socket, handler, &_active);
    thr.detach();
    bthread = std::move(thr);

    _active = 1;
}

void BluetoothListener::stop()
{
    if (bthread.joinable())
        bthread.join();


    _active = 0;
}

int BluetoothListener::isActive() const
{
    return _active;
}