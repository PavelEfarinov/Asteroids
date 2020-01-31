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
    mImaginaryProjections.resize(4, mProjection);
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
    textureSize.x = mProjection.getTexture()->getSize().x * mProjection.getScale().x;
    textureSize.y = mProjection.getTexture()->getSize().y * mProjection.getScale().y;

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

    std::vector<sf::Vector2f> imaginaryPositions(4, mPosition);

    // locating imaginary projections
    if (mPosition.y < 0) {
        imaginaryPositions[0].y = sceneSize.y + mPosition.y;
        imaginaryPositions[1].y = sceneSize.y + mPosition.y;
    } else if (mPosition.y > sceneSize.y - textureSize.y) {
        imaginaryPositions[2].y = mPosition.y - sceneSize.y;
        imaginaryPositions[3].y = mPosition.y - sceneSize.y;
    }
    if (mPosition.x < 0) {
        imaginaryPositions[0].x = sceneSize.x + mPosition.x;
        imaginaryPositions[2].x = sceneSize.x + mPosition.x;
    } else if (mPosition.x > sceneSize.x - textureSize.x) {
        imaginaryPositions[1].x = mPosition.x - sceneSize.x;
        imaginaryPositions[3].x = mPosition.x - sceneSize.x;
    }

    for (int i = 0; i < 4; ++i) {
        mImaginaryProjections[i].setPosition(imaginaryPositions[i]);
    }
    mProjection.setPosition(mPosition);
}

void SpaceBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mProjection);
    for (auto& imaginaryProjection: mImaginaryProjections) {
        target.draw(imaginaryProjection);
    }
}

SpaceBody::~SpaceBody() {
    //TODO violates standards of heap memory usage
    delete &mProjection;
}
