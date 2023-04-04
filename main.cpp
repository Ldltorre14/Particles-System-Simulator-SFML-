#include <SFML/Graphics.hpp>

#define WIDTH 900
#define HEIGHT 600

int main() {

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particles System Simulation");
	window.setFramerateLimit(240);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				window.close();
			}



		}
	}

}
