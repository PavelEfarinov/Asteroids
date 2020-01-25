//
// Created by lizzka239 on 1/25/2020.
//

#ifndef ASTROSFML_BULLET_H
#define ASTROSFML_BULLET_H


#include <SFML/System.hpp>
#include "SpaceBody.h"

class Bullet: public SpaceBody {
public:

    Bullet(sf::Vector2f position, sf::Vector2f speed, sf::Sprite& sprite);

    bool isOutOfBounds(sf::Vector2f sceneSize);
};


#endif //ASTROSFML_BULLET_H
