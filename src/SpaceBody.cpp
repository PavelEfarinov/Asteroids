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
    mProjection.setOrigin(mProjection.getTexture()->getSize().x / 2,
                          mProjection.getTexture()->getSize().y / 2);
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
    sf::Vector2u textureSize = mImaginaryProjection.getTexture()->getSize();

    sf::FloatRect commonArea;
    mImaginaryProjection.getGlobalBounds().intersects(sf::FloatRect(0, 0, sceneSize.x, sceneSize.y), commonArea);

    if (commonArea.height < textureSize.y) {
        imaginaryPosition.y = sceneSize.y + mPosition.y;
    }
    if (commonArea.width < textureSize.x) {
        imaginaryPosition.x = sceneSize.x - mPosition.x;
    }


    if (mPosition.x > sceneSize.x) {
        mPosition.x -= int(mPosition.x / sceneSize.x) * sceneSize.x;
    } else if (mPosition.x < 0) {
        mPosition.x -= int(mPosition.x / sceneSize.x) * sceneSize.x;
        mPosition.x += sceneSize.x;
    }
    if (mPosition.y > sceneSize.y) {
        mPosition.y -= int(mPosition.y / sceneSize.y) * sceneSize.y;
    } else if (mPosition.y < 0) {
        mPosition.y -= int(mPosition.y / sceneSize.y) * sceneSize.y;
        mPosition.y += sceneSize.y;
    }

    //TODO add imaginary projection
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
