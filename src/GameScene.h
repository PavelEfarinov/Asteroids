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
#include "CommandReader.h"

class GameScene: public sf::Drawable {
public:
    GameScene();

    void init();

    void processFrame(const CommandReader& commandReader);

    ~GameScene();
private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Clock mGameTimer;
    sf::Sprite mBackground;
};


#endif //ASTEROIDS_GAMESCENE_H
