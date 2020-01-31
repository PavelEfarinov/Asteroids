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
    for (auto asteroid: mAsteroids) {
        delete asteroid;
    }
}

void GameScene::processFrame(const CommandReader&) {
    if (mGameTimer.getElapsedTime().asMilliseconds() - mLastAsteroidSpawn.asMilliseconds() > mAsteroidSpawnDelay) {
        auto* asteroid = new sf::Sprite;
        asteroid->setTexture(mAsteroidTexture);

        mAsteroids.push_back(new Asteroid(sf::Vector2f(mWorldSize.x / 2.0, mWorldSize.y / 2.0),
                                          sf::Vector2f((10 - rand() % 20) / mAsteroidSpeed, (10 - rand() % 20) / mAsteroidSpeed), *asteroid,
                                          1));
        mLastAsteroidSpawn = mGameTimer.getElapsedTime();
    }
    for (auto asteroid: mAsteroids) {
        asteroid->move(mFrameTime - mGameTimer.getElapsedTime(), mWorldSize);
    }
    mFrameTime = mGameTimer.getElapsedTime();
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

    mAsteroidTexture.loadFromFile("..\\resources\\asteroid.png");

    for (int i = 0; i < mInitialAsteroidsNumber; ++i) {
        auto asteroid = new sf::Sprite;
        asteroid->setTexture(mAsteroidTexture);
        mAsteroids.push_back(new Asteroid(sf::Vector2f(target.getSize().x / 2.0, target.getSize().y / 2.0),
                                          sf::Vector2f((10 - rand() % 20) / mAsteroidSpeed, (10 - rand() % 20) / mAsteroidSpeed), *asteroid,
                                          1));
    }
    mLastAsteroidSpawn = mGameTimer.getElapsedTime();
    //TODO initialize player ship and asteroids
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(*mBackground);

    for (auto asteroid: mAsteroids) {
        target.draw(*asteroid);
    }
}
