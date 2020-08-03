//
// Created by kirill on 03.08.2020.
//

#ifndef SUPERDIMENSION_WALL_H
#define SUPERDIMENSION_WALL_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Wall
{
public:
    Wall();
    //explicit Wall(const sf::Texture& texture);

    void SetTexture(const sf::Texture& texture);
    void SetPosition(float x, float y);
    //void SetPosition(const sf::Vector2f& vector);

    void Draw(sf::RenderWindow& window);

private:
    sf::Sprite sprite;
    sf::RectangleShape hit_box;

    void UpdateHitBox();
};

#endif //SUPERDIMENSION_WALL_H
