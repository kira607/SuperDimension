//
// Created by kirill on 12.06.2020.
//

#ifndef SUPERDIMENSION_GAME_H
#define SUPERDIMENSION_GAME_H

#include <SFML/Graphics.hpp>
#include "character.h"

class Game
{
public:
    Game();
    void MainLoop();
private:
    sf::RenderWindow window;
    const float screen_width;
    const float screen_height;

    struct
    {
        sf::Texture character_texture;
        sf::Texture floor;
    } textures;

    Character character;
    std::vector<sf::Sprite> f;
    sf::View view;
};


#endif //SUPERDIMENSION_GAME_H
