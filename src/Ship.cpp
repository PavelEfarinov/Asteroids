//
// Created by lizzka239 on 1/24/2020.
//

#include "Ship.h"

Ship::Ship( sf::Vector2f acceleration, sf::Vector2f pos, sf::Vector2f speed, sf::Sprite& sprite, double healthPoint) : Hitable(
        healthPoint), SpaceBody(pos, speed, acceleration, sprite) {
    topSpeed = speed; // TODO decide how to calculate topSpeed
}

bool Ship::processHit(double harmPoint) {
    mHealthPoint -= harmPoint;
    return mHealthPoint <= 0;
}

void Ship::rotate(double angle) {
    mRotation += angle;
}

void Ship::shoot() {
    sf::Texture bulletTexture; //TODO we need the texture itself
    sf::Sprite bulletSprite(bulletTexture);
    mBullets.emplace_back(Bullet(mPosition, mSpeed, bulletSprite));
}

void Ship::move() {
    // TODO implement the moving method
}
