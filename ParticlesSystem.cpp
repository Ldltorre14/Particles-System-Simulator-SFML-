#include "ParticlesSystem.h"
#include <iostream>
#include <math.h>

//Default constructor
ParticlesSystem::ParticlesSystem() {
	for (int i = 0; i < 100; i++) {
		Particle p;
		this->particles.push_back(p);
	}
}

//Constructor with a vector of n particles as a parameter
ParticlesSystem::ParticlesSystem(std::vector<Particle> particles) {
	this->particles = particles;
}




void ParticlesSystem::update(const sf::RenderWindow& window, float dt) {
    int counter = 0;
    for (auto& particle : this->particles) {
        particle.update(window, dt);
    }
    for (auto& particle1 : this->particles) {
        for (auto& particle2 : this->particles) {
            if (&particle1 == &particle2) {
                continue; // skip self-collision
            }
            float distance = sqrtf((particle1.Position.x - particle2.Position.x) * (particle1.Position.x - particle2.Position.x) + (particle1.Position.y - particle2.Position.y) * (particle1.Position.y - particle2.Position.y));
            float overlap = 0.5f * (distance - particle1.getRadius() - particle2.getRadius());
            if (distance < particle1.getRadius() + particle2.getRadius()) {
                counter++;
                sf::Vector2f initialVelocity = particle2.Velocity;
                if (particle1.mass != particle2.mass) {
                    particle1.Velocity = (((particle1.mass - particle2.mass) / (particle1.mass + particle2.mass)) * particle1.Velocity) + (((2 * particle2.mass) / (particle1.mass + particle2.mass)) * particle2.Velocity);
                    particle2.Velocity = (((2 * particle1.mass) / (particle1.mass + particle2.mass)) * particle1.Velocity) + (((particle2.mass - particle1.mass) / (particle1.mass + particle2.mass)) * particle2.Velocity);
                }
                else {
                    particle2.Velocity = -particle1.Velocity;
                    particle1.Velocity = -initialVelocity;
                }
                
             
            }
        }
    }
    std::cout << "Collisions: " << counter << '\n';
}

void ParticlesSystem::draw(sf::RenderWindow& window) {
	for (auto& it : this->particles) {
		it.draw(window);
	}
}

