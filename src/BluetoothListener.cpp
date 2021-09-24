#include <BluetoothListener.hpp>
#include <BluetoothWrapper.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>

BluetoothListener::BluetoothListener(int port) : port(port) {}

void BluetoothListener::start(Handler handler)
{

    _active = 1;

    std::thread thr(start_socket, handler, &_active, port);
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

int BluetoothListener::init()
{

    char buf[128];
    std::string command("stdbuf -oL hcitool dev | stdbuf -oL sed -rn 's/^(\\s)*([a-zA-Z0-9]+)(\\s)+(.*)$/\\2/p'");
    FILE *input = popen(command.c_str(), "r");
    system(command.c_str());
    while (fgets(buf, sizeof(buf), input) != NULL)
    {
    }
    system("sudo systemctl daemon-reload");
    system("sudo systemctl restart bluetooth");
    if (isspace(buf[strlen(buf) - 1]))
    {
        buf[strlen(buf) - 1] = '\0';
    }
    char piscan_command[sizeof(buf)];
    sprintf(piscan_command, "sudo hciconfig %s piscan", buf);
    system(piscan_command);
    return 0;
}