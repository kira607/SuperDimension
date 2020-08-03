//
// Created by kirill on 11.06.2020.
//

#include <iostream>
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
    SetUpHitBox();
}

sf::Vector2f Creature::GetPosition() const
{
    return sprite.getPosition();
}

void Creature::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(hit_box);
}

void Creature::SetTexture(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    SetUpHitBox();
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

void Creature::SetUpHitBox()
{
    if(hit_box.getRadius() == 0 && sprite.getTexture() != nullptr)
    {
        hit_box.setPointCount(30);
        hit_box.setFillColor(sf::Color(255,0,0,70));
        hit_box.setRadius(sprite.getGlobalBounds().width / 2);
        hit_box.setOrigin(sf::Vector2f{hit_box.getRadius(),hit_box.getRadius()});
    }
}
