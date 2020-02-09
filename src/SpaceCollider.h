//
// Created by fools on 2/9/2020.
//

#ifndef ASTROSFML_SPACECOLLIDER_H
#define ASTROSFML_SPACECOLLIDER_H


#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

class SpaceCollider {
public:
    static bool areTouching(const std::vector<sf::Sprite>&, const std::vector<sf::Sprite>&);

    static float calcuateSquareDistance(const sf::FloatRect&, const sf::FloatRect&);
};

#endif //ASTROSFML_SPACECOLLIDER_H
