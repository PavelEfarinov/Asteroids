//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_SPACEBODY_H
#define ASTEROIDS_SPACEBODY_H

#include <SFML/Graphics.hpp>

class SpaceBody : public sf::Drawable {
public:
    SpaceBody(sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f acceleration, sf::Sprite& sprite);

    void move(sf::Time time, sf::Vector2u sceneSize);

    ~SpaceBody();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
    sf::Vector2f mPosition;
    sf::Vector2f mSpeed; // as pixels per millisecond
    sf::Vector2f mAcceleration;
    sf::Sprite mProjection;
    std::vector<sf::Sprite> mImaginaryProjections;
};


#endif //ASTEROIDS_SPACEBODY_H
