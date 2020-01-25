//
// Created by fools on 1/24/2020.
//

#include "GameScene.h"

GameScene::GameScene() {
    mBackground = new sf::Sprite;
    mBackgroundTexture = new sf::Texture;
}

GameScene::~GameScene() {
    delete mBackgroundTexture;
}

void GameScene::processFrame(const CommandReader&) {
    for (auto asteroid: mAsteroids) {
        asteroid->move(mGameTimer.getElapsedTime(), mWorldSize);
    }
    mGameTimer.restart();
}

void GameScene::init(const sf::RenderTarget& target) {
    mGameTimer.restart();

    if (mBackgroundTexture->loadFromFile("..\\resources\\spaceBackground.png")) {
        mBackground->setTexture(*mBackgroundTexture);
    }

    float factorX = float(target.getSize().x) / float(mBackgroundTexture->getSize().x);
    float factorY = float(target.getSize().y) / float(mBackgroundTexture->getSize().y);
    mBackground->setScale(factorX, factorY);
    mWorldSize = target.getSize();

    sf::Sprite* asteroid = new sf::Sprite;

    if (mAsteroidTexture.loadFromFile("..\\resources\\asteroid.png")) {
        asteroid->setTexture(mAsteroidTexture);
    }

    mAsteroids.push_back(new Asteroid(sf::Vector2f(target.getSize().x / 2, target.getSize().y / 2),
                                      sf::Vector2f((10 - rand() % 20) / 50.0, (10 - rand() % 20) / 50.0), *asteroid,
                                      1));
    //TODO initialize player ship and asteroids
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(*mBackground);

    for (auto asteroid: mAsteroids) {
        target.draw(*asteroid);
    }
}
