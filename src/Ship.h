//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


#include "Hitable.h"
#include "SpaceBody.h"
#include "Bullet.h"

class Ship: public Hitable, public SpaceBody {
public:
    Ship(sf::Vector2f acceleration, sf::Vector2f pos, sf::Vector2f speed, sf::Sprite& sprite, double healthPoint);

    bool processHit(double harmPoint);

    void rotate(double angle);

    void shoot();

    void move();
private:
    sf::Vector2f topSpeed;
    double mRotation = 0;
    std::vector<Bullet> mBullets;
};


#endif //ASTEROIDS_SHIP_H
