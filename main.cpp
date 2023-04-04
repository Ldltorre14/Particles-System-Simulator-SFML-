#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"

#define WIDTH 900
#define HEIGHT 600
#define FPS 60.f

int main() {

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particles System Simulation");
	window.setFramerateLimit(FPS);
	Particle p1;

	while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    // Update and draw the particle
    window.clear();
    p1.update(window);
    p1.draw(window);
    window.display();
}

}
