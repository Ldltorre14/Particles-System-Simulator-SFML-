#include "Particle.h"
#include <cstdlib>

Particle::Particle() {
    this->Velocity = sf::Vector2f(0.f, 0.f);
    this->Position = sf::Vector2f(0.f, 0.f);
    this->Acceleration = 0.f;

    // Set the default values for the CircleShape object inherited from the Particle class
    this->setRadius(5.f);
    this->setFillColor(sf::Color::Blue);
    this->setOrigin(this->getRadius(), this->getRadius());
}

void Particle::draw(sf::RenderWindow& window) {
    window.draw(*this);
}

bool Particle::isOutOfBounds(const sf::RenderWindow& window) {
    //We check if the particle position is:
    //bigger than right bound(x > window.x)
    //Lesser than left bound(x < window.x)
    //is under the bottom bound(y > window.y)
    //above the upper bound(y < window.y)
    if (this->Position.x >= window.getSize().x || this->Position.x <= 0 || 
        this->Position.y >= window.getSize().y || this->Position.y <= 0)
        return true;
    return false;
}

void Particle::reset(const sf::RenderWindow& window, sf::Vector2f Velocity, float Acceleration) {
    this->Velocity = Velocity;
    this->Acceleration = Acceleration;

    //A new random x and y cord is generated for the particle
    this->Position.x = static_cast<float>(rand() % window.getSize().x);
    this->Position.y = static_cast<float>(rand() % window.getSize().y);
}
