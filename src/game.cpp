//
// Created by kirill on 12.06.2020.
//

#include "game.h"

#include <cmath>

Game::Game():
    window(sf::VideoMode::getFullscreenModes().at(0),"Super dimension",sf::Style::Fullscreen),
    screen_height{static_cast<float>(window.getSize().y)},
    screen_width{static_cast<float>(window.getSize().x)}
{
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true);
    window.setMouseCursorVisible(true);

    if(!textures.Load())
    {
        throw std::exception();
    }

    character.SetTexture(textures.character);

    floor_sprites.resize(36);
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            floor_sprites.at(i * 6 + j).setTexture(textures.floor);
            floor_sprites.at(i * 6 + j).setPosition(float(i * 500), float(j * 500));
            floor_sprites.at(i * 6 + j).setScale(5,5);
        }
    }

    wall.SetTexture(textures.wall);
    wall.SetPosition(100,0);


    view.setSize({screen_width/2,screen_height/2});
    view.setCenter(character.GetPosition());
    window.setView(view);
}

void Game::Run()
{
    MainLoop();
}

void Game::MainLoop()
{
    while (window.isOpen())
    {
        HandleEvents();
        Update();
        Draw();
    }
}

void Game::HandleEvents()
{
    sf::Event event{};
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
}

void Game::Update()
{
/// Logic ///

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }

    character.Update();

    view.setCenter(character.GetPosition() + CalculateCameraOffset());
    window.setView(view);
}

void Game::Draw()
{
    window.clear();
    for(int i = 0, j = 0; i < 36; ++i, ++j)
    {
        window.draw(floor_sprites.at(i));
    }
    wall.Draw(window);
    character.Draw(window);
    window.display();
}

sf::Vector2f Game::CalculateCameraOffset() const
{
    sf::Vector2f offset{sf::Mouse::getPosition()};
    offset.x -= screen_width/2;
    offset.y -= screen_height/2;
    double offset_length = std::sqrt((offset.x * offset.x) + (offset.y * offset.y));
    offset.x /= ( offset_length==0 ) ? 1 : offset_length;
    offset.y /= ( offset_length==0 ) ? 1 : offset_length;
    double k = 0.07 * offset_length;
    offset.x *= k;
    offset.y *= k;
    return offset;
}

bool Game::Textures::Load()
{
    if(!character.loadFromFile("./textures/character_simple.png"))
    {
        return false;
    }
    if(!wall.loadFromFile("./textures/wall.png"))
    {
        return false;
    }
    return floor.loadFromFile("./textures/floor.png");
}
