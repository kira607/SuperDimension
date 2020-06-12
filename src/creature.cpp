//
// Created by kirill on 11.06.2020.
//

#include "creature.h"

Creature::Creature(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    Init();
}

Creature::Creature()
{
    Init();
}

void Creature::Init()
{
    max_health_points = health_points = 100;
    speed = 5.f;
    alive = true;
}

sf::Vector2f Creature::GetPosition() const
{
    return sprite.getPosition();
}

void Creature::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Creature::SetTexture(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Creature::AddHealth(int hp)
{
    if(int new_health = (health_points + hp) > max_health_points)
    {
        health_points = max_health_points;
    }
    else
    {
        health_points = new_health;
    }
}

void Creature::ReduceHealth(int hp)
{
    if(int new_health = (health_points - hp) < max_health_points)
    {
        alive = false;
    }
    else
    {
        health_points = new_health;
    }
}

void Creature::SetMaxHealth(int hp)
{
    max_health_points = hp;
}
