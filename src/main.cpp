#include <JsonParser.hpp>
#include <SoundBoard.hpp>
#include <ErrorCodes.hpp>
#include <iostream>
#include <BluetoothListener.hpp>
#include <thread>
#include <chrono>

int main()
{
    try
    {

        /////////////////////////
        // load json elements  //
        /////////////////////////
        
        std::string file = "config.json";
        JsonParser parser(file);

        // Remember to check for "" as return value for getSoundPathByButtonID
        std::cout << parser.getSoundPathByButtonID(1) << std::endl;

        /////////////////////////
        //initialize soundbaord//
        /////////////////////////

        SoundBoard soundboard1;
        soundboard1.initUsingConfig(parser.getConfig());
    }
    catch (int error)
    {
        printError(error);
    }
}