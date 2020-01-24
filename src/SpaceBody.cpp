//
// Created by lizzka239 on 1/24/2020.
//

#include "SpaceBody.h"

SpaceBody::SpaceBody(sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f acceleration, sf::Sprite& sprite)  {
    mPosition = pos;
    mSpeed = speed;
    mAcceleration = acceleration;
    mProjection = sprite;
}

void SpaceBody::move(sf::Time time) {
    mPosition = mPosition +
}