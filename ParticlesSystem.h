#pragma once
#include "Particle.h"


class ParticlesSystem {
public:
	std::vector<Particle> particles;

	ParticlesSystem();
	ParticlesSystem(std::vector<Particle>);
};
