#pragma once
#include "Particle.h"


class ParticlesSystem {
public:
	std::vector<Particle> particles;

	ParticlesSystem();
	ParticlesSystem(std::vector<Particle>);
	void update(const sf::RenderWindow&, float);
	void draw(sf::RenderWindow&);
};
