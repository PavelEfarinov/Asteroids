//
// Created by fools on 1/24/2020.
//

#ifndef ASTEROIDS_GAMESCENE_H
#define ASTEROIDS_GAMESCENE_H

#include<SFML/System/Clock.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/Drawable.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Texture.hpp>
#include "SpaceCollider.h"
#include "CommandReader.h"
#include "SpaceBody.h"
#include "Asteroid.h"
#include "Ship.h"

class GameScene : public sf::Drawable {
public:
    GameScene();

    void init(const sf::RenderTarget& target);

    void processFrame(const CommandReader& commandReader);

    ~GameScene();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    const double mAsteroidSpawnDelay = 1500;
    const double mAsteroidSpeed = 50;
    const int mInitialAsteroidsNumber = 3;

    std::vector<Asteroid*> mAsteroids;
    Ship* mPlayerShip;
    sf::Clock mGameTimer;
    sf::Time mFrameTime;
    sf::Time mLastAsteroidSpawn;

    sf::Vector2u mWorldSize;
    sf::Texture mAsteroidTexture;
    sf::Sprite* mBackground;
    sf::Texture* mBackgroundTexture;
    sf::Texture* mShipTexture;
    sf::Sprite* mShipSprite;

    void checkCollisions();
};


#endif //ASTEROIDS_GAMESCENE_H
