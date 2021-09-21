#include <JsonParser.h>
#include <SoundBoard.h>
#include <ErrorCodes.h>
#include <iostream>
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