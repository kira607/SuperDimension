//
// Created by kirill on 11.06.2020.
//

#include "creature.h"

Creature::Creature(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Creature::Move()
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


sf::Vector2f Creature::GetPosition() const
{
    return sprite.getPosition();
}

void Creature::SetRotation(float angle)
{
    sprite.setRotation(angle);
}

void Creature::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
