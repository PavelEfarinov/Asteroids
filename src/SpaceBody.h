//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_SPACEBODY_H
#define ASTEROIDS_SPACEBODY_H

#include <SFML/Graphics.hpp>

class SpaceBody {
public:
    SpaceBody(sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f acceleration, sf::Sprite& sprite);
    virtual void move(sf::Time time);
protected:
    sf::Vector2f mPosition;
    sf::Vector2f mSpeed;
    sf::Vector2f mAcceleration;
    sf::Sprite mProjection;
};


#endif //ASTEROIDS_SPACEBODY_H
