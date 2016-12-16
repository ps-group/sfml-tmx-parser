#include <iostream>
#include "level.h"

using namespace std;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    try
    {
        Level lvl;
        lvl.LoadFromFile("res/platformer.tmx");
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
