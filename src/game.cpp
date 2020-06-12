//
// Created by kirill on 12.06.2020.
//

#include "game.h"

Game::Game():
    window(sf::VideoMode::getFullscreenModes().at(0),"Super dimension",sf::Style::Fullscreen),
    screen_height{static_cast<float>(window.getSize().y)},
    screen_width{static_cast<float>(window.getSize().x)}
{
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true);
    window.setMouseCursorVisible(true);

    textures.character_texture.loadFromFile("../textures/character.png");
    textures.floor.loadFromFile("../floor.png");

    character.SetTexture(textures.character_texture);

    f.resize(36);
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            f.at(i*6+j).setTexture(textures.floor);
            f.at(i*6+j).setPosition(i*500,j*500);
        }
    }

    view.setSize({screen_width/2,screen_height/2});
    view.setCenter(character.GetPosition());

    //double max_len = sqrt((screen_width/2) * (screen_width/2) + (screen_height/2) * (screen_height/2));
    window.setView(view);
}

void Game::MainLoop()
{
    while (window.isOpen())
    {
        sf::Event event{};

        /// Events ///

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {

            }
            if(event.type == sf::Event::MouseMoved)
            {

            }
            if(event.type == sf::Event::TextEntered)
            {

            }
        }

        /// Logic ///

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        character.Update();





        sf::Vector2f offset{sf::Mouse::getPosition()};
        offset.x -= screen_width/2;
        offset.y -= screen_height/2;
        double offset_length = sqrt((offset.x * offset.x) + (offset.y * offset.y));
        sf::Vector2f rot = offset;
        offset.x /= ( offset_length==0 ) ? 1 : offset_length;
        offset.y /= ( offset_length==0 ) ? 1 : offset_length;
        double k = 0.07 * offset_length;
        offset.x *= k;
        offset.y *= k;

        view.setCenter(character.GetPosition() + offset);
        window.setView(view);

        /// DRAW ///

        window.clear();
        for(int i = 0, j = 0; i < 36; ++i, ++j)
        {
            window.draw(f.at(i));
        }
        character.Draw(window);
        window.display();
    }
}
