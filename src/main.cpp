#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "CommandReader.h"

int main() {
    using namespace sf;
    RenderWindow window(VideoMode::getDesktopMode(), "space", sf::Style::Fullscreen);

    GameScene gameScene;
    CommandReader reader;
    gameScene.init();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {

            reader.updateKeyboard(event);

            if (event.type == Event::Closed) {
                window.close();
            }
        }

        gameScene.processFrame(reader);

        window.clear(Color::White);
        window.draw(gameScene);
        window.display();
    }
}
