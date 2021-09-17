#include "jsonParser.h"
#include "SoundBoard.h"
#include <iostream>
int main()
{
    std::string file = "config.json";

    JsonParser parser(file);
    std::cout << parser.getSoundPathByButtonID(1) << std::endl;
}