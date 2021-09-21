#include <JsonParser.h>
#include <SoundBoard.h>
#include <ErrorCodes.h>
#include <iostream>
#include <BluetoothListener.h>
#include <thread>
#include <chrono>

void print_int(int num)
{
    std::cout << "Num is " << num << std::endl;
}
int main()
{
    try
    {
        /* std::string file = "config.json";
        JsonParser parser(file);

        // Remember to check for "" as return value for getSoundPathByButtonID
        std::cout << parser.getSoundPathByButtonID(1) << std::endl; */
        BluetoothListener listener;
        listener.start(print_int);
        //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        while(1)
        {}
    }
    catch (int error)
    {
        printError(error);
    }
}