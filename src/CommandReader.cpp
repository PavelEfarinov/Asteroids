//
// Created by fools on 1/24/2020.
//

#include "CommandReader.h"

CommandReader::CommandReader() {
    mKeys = new std::vector<bool>(sf::Keyboard::KeyCount, false);
    mLastReleased = sf::Keyboard::Key::Unknown;
}

void CommandReader::updateKeyboard(sf::Event e) {
    mLastReleased = sf::Keyboard::KeyCount;
    switch (e.type) {
        case sf::Event::KeyReleased:
            mLastReleased = e.key.code;
            (*mKeys)[e.key.code] = false;
            break;

        case sf::Event::KeyPressed:
            (*mKeys)[e.key.code] = true;
            break;

        default:
            break;
    }
}

bool CommandReader::isKeyDown(sf::Keyboard::Key key) const {
    return (*mKeys)[key];
}

bool CommandReader::keyReleased(sf::Keyboard::Key key) const {
    return mLastReleased == key;
}

CommandReader::~CommandReader() {
    delete mKeys;
}
