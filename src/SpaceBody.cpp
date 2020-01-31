//
// Created by lizzka239 on 1/24/2020.
//

#include <iostream>
#include "SpaceBody.h"

SpaceBody::SpaceBody(sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f acceleration, sf::Sprite& sprite) {
    mPosition = pos;
    mSpeed = speed;
    mAcceleration = acceleration;
    mProjection = sprite;
    mProjection.setScale(7, 7);
    mImaginaryProjection = sf::Sprite(mProjection);
}

void SpaceBody::move(sf::Time time, sf::Vector2u sceneSize) {
    double distanceX =
            mSpeed.x * time.asMilliseconds() + mAcceleration.x * time.asMilliseconds() * time.asMilliseconds();
    double distanceY =
            mSpeed.y * time.asMilliseconds() + mAcceleration.y * time.asMilliseconds() * time.asMilliseconds();
    mSpeed.x += mAcceleration.x * time.asMilliseconds();
    mSpeed.y += mAcceleration.y * time.asMilliseconds();
    mPosition += sf::Vector2f(distanceX, distanceY);

    sf::Vector2f imaginaryPosition(mPosition);
    sf::Vector2u textureSize;
    textureSize.x = mImaginaryProjection.getTexture()->getSize().x * mImaginaryProjection.getScale().x;
    textureSize.y = mImaginaryProjection.getTexture()->getSize().y * mImaginaryProjection.getScale().y;

    if (mPosition.x > sceneSize.x) {
        mPosition.x -= int(mPosition.x / sceneSize.x) * sceneSize.x;
    } else if (mPosition.x < -int(textureSize.y)) {
        mPosition.x -= int(mPosition.x / sceneSize.x) * sceneSize.x;
        mPosition.x += sceneSize.x;
    }
    if (mPosition.y > sceneSize.y) {
        mPosition.y -= int(mPosition.y / sceneSize.y) * sceneSize.y;
    } else if (mPosition.y < -int(textureSize.y)) {
        mPosition.y -= int(mPosition.y / sceneSize.y) * sceneSize.y;
        mPosition.y += sceneSize.y;
    }
    // locating imaginary projection
    if (mPosition.y < 0) {
        imaginaryPosition.y = sceneSize.y + mPosition.y;
    } else if (mPosition.y > sceneSize.y - textureSize.y) {
        imaginaryPosition.y = sceneSize.y - mPosition.y;
    }
    if (mPosition.x < 0) {
        imaginaryPosition.x = sceneSize.x + mPosition.x;
    } else if (mPosition.x > sceneSize.x - textureSize.x) {
        imaginaryPosition.x = sceneSize.x - mPosition.x;
    }

    //TODO add imaginary projection
//    std::cout << sceneSize.x << ' ' << sceneSize.y << " im " << imaginaryPosition.x <<' ' << imaginaryPosition.y <<" real " << mPosition.x << ' '<< mPosition.y<< '\n';
    mImaginaryProjection.setPosition(imaginaryPosition);
    mProjection.setPosition(mPosition);
}

void SpaceBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mProjection);
    target.draw(mImaginaryProjection);
}

SpaceBody::~SpaceBody() {
    //TODO violates standards of heap memory usage
    delete &mProjection;
}
