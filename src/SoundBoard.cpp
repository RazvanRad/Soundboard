#include <SoundBoard.hpp>
#include <iostream>

#include <BluetoothListener.hpp>

SoundBoard::SoundBoard() {}

void playSound(int i)
{
    std::cout << i;
}

void SoundBoard::run()
{
    //obiect bluetooth listener
    BluetoothListener listener;

    //Implement playSound (pt stefan)
    listener.start(playSound);

    while (true)
    {
        std::cout << "a" << configFile.getButtonCount();
        std::cout << "a" << configFile.getBluetoothPort();
        std::cout << "a" << configFile.getProtocol();
        std::cout << "a" << configFile.getSoundPathByButtonID(2);
        //wait for input from the raspberry pi
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        //handle input
    }
}

void SoundBoard::init(std::string &filename)
{
    configFile.loadConfig(filename);
}
