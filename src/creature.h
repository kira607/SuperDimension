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
    Creature();

    virtual void Update() = 0;
    void AddHealth(int hp);
    void ReduceHealth(int hp);

    void SetTexture(const sf::Texture &texture);
    void SetMaxHealth(int hp);


    sf::Vector2f GetPosition() const;

    virtual void Draw(sf::RenderWindow &window);

protected:
    void Init();
    virtual void UpdateRotation() = 0;
    virtual void UpdatePosition() = 0;
    int health_points;
    int max_health_points;
    sf::Sprite sprite;
    float speed;
    bool alive;
};


#endif //SUPERDIMENSION_CREATURE_H
