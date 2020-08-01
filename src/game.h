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
    void Run();
private:
    void MainLoop();
    void HandleEvents();
    void Update();
    void Draw();

    sf::Vector2f CalculateCameraOffset() const;

    sf::RenderWindow window;

    const float screen_width;
    const float screen_height;

    struct Textures
    {
        sf::Texture character;
        sf::Texture floor;
        sf::Texture wall;
        bool Load();
    } textures;

    Character character;
    std::vector<sf::Sprite> floor_sprites;
    sf::Sprite wall_sprite;
    sf::View view;
};


#endif //SUPERDIMENSION_GAME_H
