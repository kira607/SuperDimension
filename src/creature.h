//
// Created by kirill on 11.06.2020.
//

#ifndef SUPERDIMENSION_CREATURE_H
#define SUPERDIMENSION_CREATURE_H

#include <SFML/Graphics.hpp>

class Creature
{
public:
    explicit Creature(const sf::Texture &texture);
    virtual void Move() = 0;
    sf::Vector2f GetPosition() const;
    void SetRotation(float angle);
    virtual void Draw(sf::RenderWindow &window);

protected:
    sf::Sprite sprite;
    float speed = 5.f;
};


#endif //SUPERDIMENSION_CREATURE_H
