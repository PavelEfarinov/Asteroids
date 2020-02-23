//
// Created by fools on 1/24/2020.
//

#include <iostream>
#include "GameScene.h"

GameScene::GameScene() {
    mBackground = new sf::Sprite;
    mBackgroundTexture = new sf::Texture;
    mShipTexture = new sf::Texture;
    mShipSprite = new sf::Sprite;
}

GameScene::~GameScene() {
    delete mBackgroundTexture;
    for (auto asteroid: mAsteroids) {
        delete asteroid;
    }
}

void GameScene::processFrame(const CommandReader& commandReader) {
    checkCollisions();

    // Spawning new asteroid
    if (mGameTimer.getElapsedTime().asMilliseconds() - mLastAsteroidSpawn.asMilliseconds() > mAsteroidSpawnDelay) {
        auto* asteroid = new sf::Sprite;
        asteroid->setTexture(mAsteroidTexture);
        mAsteroids.push_back(new Asteroid(sf::Vector2f(mWorldSize.x / 2.0, mWorldSize.y / 2.0),
                                          sf::Vector2f((10 - rand() % 20) / mAsteroidSpeed,
                                                       (10 - rand() % 20) / mAsteroidSpeed), *asteroid,
                                          1));
        mLastAsteroidSpawn = mGameTimer.getElapsedTime();
    }

    if (commandReader.isKeyDown(sf::Keyboard::W)) {
        mPlayerShip->accelerate(sf::Vector2f(0, -0.0005));
    } else if (commandReader.isKeyDown(sf::Keyboard::S)) {
        mPlayerShip->accelerate(sf::Vector2f(0, 0.0005));
    } else {
        mPlayerShip->accelerate(sf::Vector2f(0, 0));
    }
    if (commandReader.isKeyDown(sf::Keyboard::A)) {
        mPlayerShip->rotate(-1);
    } else if (commandReader.isKeyDown(sf::Keyboard::D)) {
        mPlayerShip->rotate(1);
    }

    mPlayerShip->move(mFrameTime - mGameTimer.getElapsedTime(), mWorldSize);
    for (auto asteroid: mAsteroids) {
        asteroid->move(mFrameTime - mGameTimer.getElapsedTime(), mWorldSize);
    }
    mFrameTime = mGameTimer.getElapsedTime();
}

void GameScene::checkCollisions() {
    std::vector<std::vector<Asteroid*>::iterator> shouldDelete;

    for (auto i = mAsteroids.begin(); i < mAsteroids.end(); ++i) {
        for (auto j = i; j < mAsteroids.end(); ++j) {
            if (i != j && mGameTimer.getElapsedTime().asSeconds() > 1.5) {
                if (SpaceCollider::areTouching((*i)->getAllProjections(),
                                               (*j)->getAllProjections())) {
                    shouldDelete.push_back(i);
                    shouldDelete.push_back(j);
                }
            }
        }
    }

    while (!shouldDelete.empty()) {
        mAsteroids.erase(shouldDelete.back());
        shouldDelete.pop_back();
    }

    for (auto i = mAsteroids.begin(); i < mAsteroids.end(); ++i) {
        if (SpaceCollider::areTouchingShip((*mPlayerShip).getAllProjections(), (*i)->getAllProjections())) {
            shouldDelete.push_back(i);
        }
    }

    while (!shouldDelete.empty()) {
        mAsteroids.erase(shouldDelete.back());
        shouldDelete.pop_back();
    }
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
                                          sf::Vector2f((10 - rand() % 20) / mAsteroidSpeed,
                                                       (10 - rand() % 20) / mAsteroidSpeed), *asteroid,
                                          1));
    }

    mShipTexture->loadFromFile("..\\resources\\sheep.png");
    mShipSprite->setTexture(*mShipTexture);

    mPlayerShip = new Ship(sf::Vector2f(0, 0), sf::Vector2f(200, 200), sf::Vector2f(0, 0), *mShipSprite, 1000);

    mLastAsteroidSpawn = mGameTimer.getElapsedTime();
    //TODO initialize player ship and asteroids
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(*mBackground);
    target.draw(*mPlayerShip);
    for (auto asteroid: mAsteroids) {
        target.draw(*asteroid);
    }
}
