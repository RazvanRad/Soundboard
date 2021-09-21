#include <BluetoothWrapper.h>
#include <BluetoothListener.h>
#include <thread>

void BluetoothListener::start(Handler handler)
{
    active = 1;
    std::thread thr(start_socket, handler, &active);
    thr.detach();
    bthread = std::move(thr);
}

void BluetoothListener::stop()
{
    active = 0;
    if (bthread.joinable())
        bthread.join();
}