//
// Created by kirill on 11.06.2020.
//

#ifndef SUPERDIMENSION_CHARACTER_H
#define SUPERDIMENSION_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "creature.h"

class Character : public Creature
{
public:
    explicit Character(const sf::Texture &texture);
    Character();
    void Update() override;
private:
    void UpdateRotation() override;
    void UpdatePosition() override;
    void Move();
};

#endif //SUPERDIMENSION_CHARACTER_H
