#include "Particle.h"
#include <cstdlib>

Particle::Particle() {
    this->Velocity = sf::Vector2f(50.f, 50.f);
    this->Position = sf::Vector2f(0.f, 0.f);
    this->Acceleration = sf::Vector2f(0.f, 9.8f);

    // Set the default values for the CircleShape object inherited from the Particle class
    this->setRadius(5.f);
    this->setFillColor(sf::Color::Blue);
    this->setOrigin(this->getRadius(), this->getRadius());
}

void Particle::update(const sf::RenderWindow& window) {
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();

    this->Velocity = this->Velocity + this->Acceleration * dt;
    this->Position = this->Position + this->Velocity * dt;

    //The Particle hits the right border
    if (this->Position.x > window.getSize().x + this->getRadius()) {
        this->Position.x = window.getSize().x;
        this->Velocity.x = -this->Velocity.x;   
    }
    //The Particle hits the left border
    else if (this->Position.x < 0) {
        this->Position.x = 0;
        this->Velocity.x = -this->Velocity.x;
    }
    //The Particle hits the bottom border
    else if (this->Position.y > window.getSize().y) {
        this->Position.y = window.getSize().y;
        this->Velocity.y = -this->Velocity.y;
        this->Acceleration.y = -this->Acceleration.y;
    }
    //The Particle hits the upper border
    else if (this->Position.y < 0) {
        this->Position.y = 0;
        this->Velocity.y = -this->Velocity.y;
        this->Acceleration.y = -this->Acceleration.y;
    }

    this->setPosition(this->Position);
    
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
    if (this->Position.x > window.getSize().x || this->Position.x < 0 || 
        this->Position.y > window.getSize().y || this->Position.y < 0)
        return true;
    return false;
}

void Particle::reset(const sf::RenderWindow& window, sf::Vector2f Velocity, sf::Vector2f Acceleration) {
    this->Velocity = Velocity;
    this->Acceleration = Acceleration;

    //A new random x and y cord is generated for the particle
    this->Position.x = static_cast<float>(rand() % window.getSize().x);
    this->Position.y = static_cast<float>(rand() % window.getSize().y);
}
