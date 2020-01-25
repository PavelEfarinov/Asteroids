//
// Created by lizzka239 on 1/24/2020.
//

#include "Asteroid.h"

Asteroid::Asteroid(sf::Vector2f pos, sf::Vector2f speed, sf::Sprite& sprite, double healthPoint) : SpaceBody(pos, speed,
        sf::Vector2f(), sprite), Hitable(healthPoint) {}

bool Asteroid::processHit(double harmPoint) {
    mCurrentHealth -= harmPoint;
    return mCurrentHealth <= 0;
}

