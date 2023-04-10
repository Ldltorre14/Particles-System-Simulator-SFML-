#include "Particle.h"
#include <cstdlib>
#include <iostream>

Particle::Particle() {
    //srand(time(NULL));
    
    this->Velocity.x = static_cast<float>(rand() % 5);
    this->Velocity.y = static_cast<float>(rand() % 5);
    this->Position.x = static_cast<float>(rand() % 900);
    this->Position.y = static_cast<float>(rand() % 600);
    this->Acceleration = sf::Vector2f(0.f, 9.8f);
    this->mass = static_cast<float>(rand() % 1);

    // Set the default values for the CircleShape object inherited from the Particle class
    this->setRadius(5.f);
    sf::Color color(rand() % 255, rand() % 255, rand() % 255);
    this->setFillColor(color);
    this->setOrigin(this->getRadius(), this->getRadius());
    this->setPosition(this->Position);


    
}



void Particle::update(const sf::RenderWindow& window, float dt) {
    //std::cout << "Particle with address: " << &this->Velocity << " at pos: " << this->Position.x << ", " << this->Position.y << ")\n";

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
        //this->Acceleration.y = -this->Acceleration.y;
    }
    //The Particle hits the upper border
    else if (this->Position.y < 0) {
        this->Position.y = 0;
        this->Velocity.y = -this->Velocity.y;
        
        //this->Acceleration.y = -this->Acceleration.y;
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

void Particle::reset(const sf::RenderWindow& window, sf::Vector2f Velocity, sf::Vector2f Acceleration, float dt) {
    this->Velocity = Velocity;
    this->Acceleration = Acceleration;

    //A new random x and y cord is generated for the particle
    this->Position.x = static_cast<float>(rand() % window.getSize().x);
    this->Position.y = static_cast<float>(rand() % window.getSize().y);
    this->update(window, dt);
}
