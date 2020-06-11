//
// Created by kirill on 31.05.2020.
//

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

int main()
{
    // окно

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "XXX",sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true);
    window.setMouseCursorVisible(true);

    const float screen_width = window.getSize().x;
    const float screen_height = window.getSize().y;

    sf::Texture character_texture;
    character_texture.loadFromFile("../textures/character.png");

    sf::Sprite character;
    character.setOrigin(character.getGlobalBounds().width / 2, character.getGlobalBounds().height / 2);
    character.setTexture(character_texture);

    float speed = 5.f;

    sf::Texture floor;
    floor.loadFromFile("../floor.png");

    std::vector<sf::Sprite> f;
    f.resize(36);
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            f.at(i*6+j).setTexture(floor);
            f.at(i*6+j).setPosition(i*500,j*500);
        }
    }

    sf::View view;
    view.setSize({screen_width/2,screen_height/2});
    view.setCenter(character.getPosition());

    //double max_len = sqrt((screen_width/2) * (screen_width/2) + (screen_height/2) * (screen_height/2));
    window.setView(view);
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            character.move(0, -speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            character.move(0, speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            character.move(speed, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            character.move(-speed, 0);
        }


        sf::Vector2f offset{sf::Mouse::getPosition()};
        offset.x -= screen_width/2;
        offset.y -= screen_height/2;
        double offset_length = sqrt((offset.x * offset.x) + (offset.y * offset.y));
        offset.x /= ( offset_length==0 ) ? 1 : offset_length;
        offset.y /= ( offset_length==0 ) ? 1 : offset_length;
        double k = 0.07 * offset_length;
        offset.x *= k;
        offset.y *= k;

        view.setCenter(character.getPosition() + offset);
        window.setView(view);

        /// DRAW ///

        window.clear();
        for(int i = 0, j = 0; i < 36; ++i, ++j)
        {
            window.draw(f.at(i));
        }
        window.draw(character);
        window.display();
    }

    return 0;
}