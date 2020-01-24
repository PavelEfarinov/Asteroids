//
// Created by fools on 1/24/2020.
//

#include "GameScene.h"

GameScene::GameScene() {
    sf::Texture backgroundTexture;
    if(backgroundTexture.loadFromFile("spaceBackground.png"))
        mBackground.setTexture(backgroundTexture);
}

GameScene::~GameScene() {

}

void GameScene::processFrame(const CommandReader&) {

}

void GameScene::init() {
    mGameTimer.restart();
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.getSize();
}
