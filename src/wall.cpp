//
// Created by kirill on 03.08.2020.
//

#include "wall.h"

Wall::Wall()
= default;

/*
Wall::Wall(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    UpdateHitBox(); //SetUpHitBox();
}
*/

void Wall::SetTexture(const sf::Texture &texture)
{
    sprite.setTexture(texture);
    UpdateHitBox(); //SetUpHitBox();
}

void Wall::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
    UpdateHitBox(); //UpdateHitBoxPosition();
}

/*
void Wall::SetPosition(const sf::Vector2f &vector)
{
    sprite.setPosition(vector);
    UpdateHitBox(); //UpdateHitBoxPosition();
}
*/

void Wall::UpdateHitBox()
{
    hit_box.setPosition(sprite.getPosition());
    sf::Vector2f new_size = sf::Vector2f{sprite.getGlobalBounds().width, sprite.getGlobalBounds().height};
    hit_box.setSize(new_size);
    hit_box.setFillColor(sf::Color(0,255,0,100));
}

void Wall::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(hit_box);
}



