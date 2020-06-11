//
// Created by kirill on 11.06.2020.
//

#include "creature.h"

Creature::Creature(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
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
