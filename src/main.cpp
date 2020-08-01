//
// Created by kirill on 31.05.2020.
//

#include <iostream>
#include "game.h"

int main()
{
    try
    {
        Game game;
        game.Run();
    }
    catch (std::exception&)
    {
        std::cout << "An error occurred while starting Game\n";
    }
    return 0;
}
