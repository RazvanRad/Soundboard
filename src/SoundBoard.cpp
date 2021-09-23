#include <SoundBoard.hpp>
#include <BluetoothListener.hpp>
#include <iostream>

SoundBoard::SoundBoard() {}

void playSound(int i)
{
    SoundManager::playSound(i);
}

void SoundBoard::run()
{
    //obiect bluetooth listener
    BluetoothListener listener;
    if (listener.init())
    {
        std::cout << "Bluetooth device was not initialized " << std::endl;
    }
    else
    {
        std::cout << "Bluetooth listener was initialized successfully" << std::endl;
    }
    //listener.start(ptf);

    //Implement playSound (pt stefan)
    listener.start(playSound);

    while (true)
    {
        //wait for input from the raspberry pi
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        //handle input
    }
}

void SoundBoard::init(std::string &filename)
{
    configFile.loadConfig(filename);
    audioManager.init(configFile);
}
