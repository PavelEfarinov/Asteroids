//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTROSFML_ASTEROID_H
#define ASTROSFML_ASTEROID_H


#include "Hitable.h"
#include "SpaceBody.h"

class Asteroid: public Hitable, public SpaceBody {
public:
    Asteroid(sf::Vector2f pos, sf::Vector2f speed, sf::Sprite& sprite, double healthPoint);
    bool processHit(double harmPoint);
};


#endif //ASTROSFML_ASTEROID_H
