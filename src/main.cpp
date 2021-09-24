#include <iostream>

#include <BluetoothListener.hpp>
#include <SoundBoard.hpp>

int main()
{
    std::string file = "../config.json";

    SoundBoard soundboard;
    soundboard.init(file);

    soundboard.run();
}