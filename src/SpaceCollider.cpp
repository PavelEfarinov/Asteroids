//
// Created by fools on 2/9/2020.
//

#include "SpaceCollider.h"

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
    return ((firstBody.left + firstBody.width / 2) - (secondBody.left + secondBody.width / 2)) *
           ((firstBody.left + firstBody.width / 2) -
            (secondBody.left + secondBody.width / 2)) +
           ((firstBody.top + firstBody.height / 2) - (secondBody.top + secondBody.height / 2)) *
           ((firstBody.top + firstBody.height / 2) -
            (secondBody.top + secondBody.height / 2));
}
