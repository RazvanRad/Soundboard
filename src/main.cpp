#include <JsonParser.hpp>
#include <SoundBoard.hpp>
#include <ErrorCodes.hpp>
#include <iostream>
#include <BluetoothListener.hpp>
#include <thread>
#include <chrono>

int main()
{
    std::string file = "config.json";

    SoundBoard soundboard;
    soundboard.init(file);
}