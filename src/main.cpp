#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "CommandReader.h"

int main() {
    using namespace sf;
    RenderWindow window(VideoMode::getDesktopMode(), "space", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    GameScene gameScene;
    CommandReader reader;
    gameScene.init(window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {

            reader.updateKeyboard(event);

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }

        gameScene.processFrame(reader);

        window.clear(Color::White);
        window.draw(gameScene);
        window.display();
    }
}
