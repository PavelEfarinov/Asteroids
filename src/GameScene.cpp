//
// Created by fools on 1/24/2020.
//

#include "GameScene.h"
#include <iostream>

GameScene::GameScene() {
    mBackground = new sf::Sprite;
    mBackgroundTexture = new sf::Texture;
}

GameScene::~GameScene() {
    delete mBackgroundTexture;
}

void GameScene::processFrame(const CommandReader&) {

}

void GameScene::init(const sf::RenderTarget& target) {
    mGameTimer.restart();

    if (mBackgroundTexture->loadFromFile("..\\resources\\spaceBackground.png")) {
        mBackground->setTexture(*mBackgroundTexture);
    }

    float factorX = float(target.getSize().x) / float(mBackgroundTexture->getSize().x);
    float factorY = float(target.getSize().y) / float(mBackgroundTexture->getSize().y);
    mBackground->setScale(factorX, factorY);

}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(*mBackground);
}
