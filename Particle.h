#pragma once
#include <SFML/Graphics.hpp>

//Particle class inhereting from CircleShape class
class Particle : public sf::CircleShape{
public:
	//ATRIBUTES
	sf::Vector2f Velocity;
	sf::Vector2f Position;
	float Acceleration;

	//METHODS
	Particle();
	void update();
	void draw(sf::RenderWindow&);
	bool isOutOfBounds(const sf::RenderWindow&);
	void reset(const sf::RenderWindow&,sf::Vector2f,float);

};
