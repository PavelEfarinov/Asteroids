//
// Created by fools on 2/9/2020.
//

#include "SpaceCollider.h"

#define min(x, y) (x > y ? y : x)

#define max(x, y) (x > y ? x : y)


bool SpaceCollider::areTouching(const std::vector<sf::Sprite>& firstArray, const std::vector<sf::Sprite>& secondArray) {
    for (const auto& firstBody : firstArray) {
        for (const auto& secondBody : secondArray) {
            if (calcuateSquareDistance(firstBody.getGlobalBounds(), secondBody.getGlobalBounds()) <
                (firstBody.getGlobalBounds().height / 2 + secondBody.getGlobalBounds().height / 2) *
                (firstBody.getGlobalBounds().height / 2 + secondBody.getGlobalBounds().height / 2)) {
                return true;
            }
        }
    }
    return false;
}

float SpaceCollider::calcuateSquareDistance(const sf::FloatRect& firstBody, const sf::FloatRect& secondBody) {
    return ((firstBody.left) - (secondBody.left)) * ((firstBody.left) - (secondBody.left)) +
           ((firstBody.top) - (secondBody.top)) * ((firstBody.top) - (secondBody.top));
}

float SpaceCollider::calcuateSquareDistance(const sf::Vector2f& firstPoint, const sf::FloatRect& secondBody) {
    return ((firstPoint.x) - (secondBody.left + secondBody.width / 2)) *
           ((firstPoint.x) - (secondBody.left + secondBody.width / 2)) +
           ((firstPoint.y) - (secondBody.top + secondBody.height / 2)) *
           ((firstPoint.y) - (secondBody.top + secondBody.height / 2));
}

double clamp(double x, double minV, double maxV) {
    return min(maxV, max(x, minV));
}


bool
SpaceCollider::areTouchingShip(const std::vector<sf::Sprite>& shipArray, const std::vector<sf::Sprite>& secondArray) {
    for (const auto& shipBody : shipArray) {
        for (const auto& secondBody : secondArray) {
            double x = clamp(secondBody.getGlobalBounds().left + secondBody.getGlobalBounds().width / 2,
                             shipBody.getGlobalBounds().left,
                             shipBody.getGlobalBounds().left + shipBody.getGlobalBounds().width);

            double y = clamp(secondBody.getGlobalBounds().top + secondBody.getGlobalBounds().height / 2,
                             shipBody.getGlobalBounds().top,
                             shipBody.getGlobalBounds().top + shipBody.getGlobalBounds().height);

            if (calcuateSquareDistance(sf::Vector2f(x, y), secondBody.getGlobalBounds()) <
                (secondBody.getGlobalBounds().height / 2) *
                (secondBody.getGlobalBounds().height / 2)) {
                return true;
            }
        }
    }
    return false;
}
