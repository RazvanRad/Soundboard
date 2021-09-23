#include <iostream>

#include <BluetoothListener.hpp>
#include <ErrorCodes.hpp>
#include <SoundBoard.hpp>

int main()
{
    std::string file = "config.json";

    SoundBoard soundboard;
    //soundboard.init(file);
    
    soundboard.run();
}