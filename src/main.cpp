#include <JsonParser.h>
#include <SoundBoard.h>
#include <ErrorCodes.h>
#include <iostream>
int main()
{
    /////////////////////////
    // load json elements  //
    /////////////////////////
    try
    {
        std::string file = "config.json";
        JsonParser parser(file);

        // Remember to check for "" as return value for getSoundPathByButtonID
        std::cout << parser.getSoundPathByButtonID(1) << std::endl;
    }
    catch (int error)
    {
        printError(error);
    }

    /////////////////////////
    //initialize soundbaord//
    /////////////////////////
    SoundBoard soundboard1;
}