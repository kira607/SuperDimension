//
// Created by kirill on 11.06.2020.
//

#include "character.h"

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

Character::Character(const sf::Texture &texture) : Creature(texture)
{

}
