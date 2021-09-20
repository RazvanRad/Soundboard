#include "JsonParser.h"
#include "SoundBoard.h"
#include "ErrorCodes.cpp"
#include <iostream>
int main()
{
    try
    {
        std::string file = "config.json";

        JsonParser parser(file);

        std::cout << parser.getSoundPathByButtonID(1) << std::endl;
    }
    catch (int error)
    {
        printError(error);
    }
}