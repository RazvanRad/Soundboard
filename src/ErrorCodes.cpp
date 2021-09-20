#include <iostream>

void printError(int error)
{
    switch (error)
    {
    case 2000000:
        std::cout << "A button does not exist" << std::endl;
        break;

    case 2000001:
        std::cout << "There are no buttons." << std::endl;
        break;

    default:
        std::cout << "encountered error " << error;
        break;
    }
}