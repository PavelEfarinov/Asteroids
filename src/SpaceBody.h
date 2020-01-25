//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_SPACEBODY_H
#define ASTEROIDS_SPACEBODY_H

#include <SFML/Graphics.hpp>

class SpaceBody {
public:
    SpaceBody(sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f acceleration, sf::Sprite& sprite);
    void move(sf::Time time, sf::Vector2f sceneSize);
protected:
    sf::Vector2f mPosition;
    sf::Vector2f mSpeed; // as pixels per milliseconds
    sf::Vector2f mAcceleration;
    sf::Sprite mProjection;
};


#endif //ASTEROIDS_SPACEBODY_H
