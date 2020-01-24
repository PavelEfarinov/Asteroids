#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by fools on 1/24/2020.
// Based on https://github.com/Hopson97/open-builder/tree/master/src/client/input
//

#ifndef ASTEROIDS_COMMANDREADER_H
#define ASTEROIDS_COMMANDREADER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

/**
 * Holds the state of the keyboard
 */
class CommandReader final {
public:
    CommandReader();

    void updateKeyboard(sf::Event e);

    bool isKeyDown(sf::Keyboard::Key key) const;

    bool keyReleased(sf::Keyboard::Key key) const;

    ~CommandReader();
private:
    std::vector<bool>* mKeys;
    sf::Keyboard::Key mLastReleased;
};

#endif //ASTEROIDS_COMMANDREADER_H

#pragma clang diagnostic pop