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

void SpaceBody::move(sf::Time time, sf::Vector2f sceneSize) {
    double distanceX = mSpeed.x * time.asMilliseconds() + mAcceleration.x * time.asMilliseconds() * time.asMilliseconds();
    double distanceY = mSpeed.y * time.asMilliseconds() + mAcceleration.y * time.asMilliseconds() * time.asMilliseconds();
    mSpeed.x += mAcceleration.x * time.asMilliseconds();
    mSpeed.y += mAcceleration.y * time.asMilliseconds();
    mPosition += sf::Vector2f(distanceX, distanceY);
    mPosition.x -= int(mPosition.x / sceneSize.x) * sceneSize.x;
    mPosition.y -= int(mPosition.y / sceneSize.y) * sceneSize.y;
}