#include <JsonParser.hpp>
#include <SoundBoard.hpp>
#include <ErrorCodes.hpp>
#include <iostream>
#include <BluetoothListener.hpp>
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
<<<<<<< HEAD
        //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        while(1)
        {}
=======
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
>>>>>>> main
    }
    catch (int error)
    {
        printError(error);
    }
}