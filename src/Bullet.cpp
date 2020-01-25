//
// Created by lizzka239 on 1/25/2020.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f speed, sf::Sprite& sprite): SpaceBody(position, speed, sf::Vector2f(), sprite) {}

bool Bullet::isOutOfBounds(sf::Vector2f sceneSize) {
    return mPosition.x > sceneSize.x || mPosition.y > sceneSize.y;
}
