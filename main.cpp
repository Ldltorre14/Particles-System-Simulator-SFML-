#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticlesSystem.h"

#define WIDTH 900
#define HEIGHT 600
#define FPS 60.f

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particles System Simulation");
    window.setFramerateLimit(FPS);
    ParticlesSystem system;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update and draw the particle
        window.clear();
        float dt = clock.restart().asSeconds();

        system.update(window, dt);
        system.draw(window);
        
        window.display();
    }

}
