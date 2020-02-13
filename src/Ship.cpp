//
// Created by lizzka239 on 1/24/2020.
//

#include "Ship.h"
#include "../../../../../MinGW/lib/gcc/mingw32/8.2.0/include/c++/cmath"

Ship::Ship(sf::Vector2f acceleration, sf::Vector2f pos, sf::Vector2f speed, sf::Sprite& sprite, double healthPoint)
        : Hitable(
        healthPoint), SpaceBody(pos, speed, acceleration, sprite) {
    // TODO decide how to calculate mTopSpeed
}

bool Ship::processHit(double harmPoint) {
    mHealthPoint -= harmPoint;
    return mHealthPoint <= 0;
}

void Ship::rotate(double angle) {
    mProjection.rotate(angle);
    mRotation = mProjection.getRotation();
}

void Ship::shoot() {
    sf::Texture bulletTexture;
    //TODO we need the texture itself
    sf::Sprite bulletSprite(bulletTexture);
    //TODO add bullets
//    mBullets.emplace_back(Bullet(mPosition, mSpeed, bulletSprite));
}

void Ship::accelerate(sf::Vector2f shipAcceleration) {
    //TODO fix strange 180 rotation behaviour
    mAcceleration.x = shipAcceleration.x * std::cos(mRotation / 360 * 2 * 3.1416) -
                      shipAcceleration.y * std::sin(mRotation / 360 * 2 * 3.1416);
    mAcceleration.y = shipAcceleration.x * std::sin(mRotation / 360 * 2 * 3.1416) +
                      shipAcceleration.y * std::cos(mRotation / 360 * 2 * 3.1416);

}

void Ship::mSpeedUp(sf::Time time) {
    SpaceBody::mSpeedUp(time);
    float currentSquareSpeed = mSpeed.x * mSpeed.x + mSpeed.y * mSpeed.y;
    if (currentSquareSpeed > mTopSpeed * mTopSpeed) {
        mSpeed.x /= std::sqrt(currentSquareSpeed) * mTopSpeed;
        mSpeed.y /= std::sqrt(currentSquareSpeed) * mTopSpeed;
    }
}