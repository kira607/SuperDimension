//
// Created by kirill on 11.06.2020.
//

#include "character.h"

#include <cmath>

Character::Character(const sf::Texture &texture) : Creature(texture) {}
Character::Character() : Creature() {}

void Character::Update()
{
    UpdateRotation();
    UpdatePosition();
}

void Character::UpdateRotation()
{
    float screen_width = 1920.f, screen_height = 1080.f; // TODO: implement logic for giving screen dimensions here
    float dX = float(sf::Mouse::getPosition().x - screen_width/2);
    float dY = sf::Mouse::getPosition().y - screen_height/2;
    float angle = std::atan2(dY, dX) * 180.f / 3.14159265; // TODO: add constant kPi
    sprite.setRotation(angle);
}

void Character::UpdatePosition()
{
    Move();
    hit_box.setPosition(sprite.getPosition());
}

void Character::Move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(speed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-speed, 0);
    }
}




