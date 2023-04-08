#include "ParticlesSystem.h"

//Default constructor
ParticlesSystem::ParticlesSystem() {
	for (int i = 0; i < 100; i++) {
		Particle p;
		this->particles.push_back(p);
	}
}

//Constructor with a vector of n particles as a parameter
ParticlesSystem::ParticlesSystem(std::vector<Particle> particles) {

}
