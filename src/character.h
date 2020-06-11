//
// Created by kirill on 11.06.2020.
//

#ifndef SUPERDIMENSION_CHARACTER_H
#define SUPERDIMENSION_CHARACTER_H

#include <SFML/Graphics.hpp>

#include "creature.h"

class Character : public Creature
{
public:
    explicit Character(const sf::Texture &texture);
    void Move() override;
};


#endif //SUPERDIMENSION_CHARACTER_H
