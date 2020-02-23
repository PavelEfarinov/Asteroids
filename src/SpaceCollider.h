//
// Created by fools on 2/9/2020.
//

#ifndef ASTROSFML_SPACECOLLIDER_H
#define ASTROSFML_SPACECOLLIDER_H


#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "Ship.h"

class SpaceCollider {
public:
    static bool areTouching(const std::vector<sf::Sprite>&, const std::vector<sf::Sprite>&);

    static bool areTouchingShip(const std::vector<sf::Sprite>& shipArray, const std::vector<sf::Sprite>& secondArray);

    static float calcuateSquareDistance(const sf::FloatRect&, const sf::FloatRect&);

    static float calcuateSquareDistance(const sf::Vector2f& firstPoint, const sf::FloatRect& secondBody);
};

#endif //ASTROSFML_SPACECOLLIDER_H
