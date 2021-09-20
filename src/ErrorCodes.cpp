#include <iostream>

void printError(int error)
{
    switch (error)
    {
    case 2000000:
        std::cout << "This is an example" << std::endl;
        break;

    default:
        std::cout << "Encountered unknown error " << error;
        break;
    }
}