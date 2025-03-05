#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), health(10), energy(10), damage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), health(10), energy(10), damage(0) {
    std::cout << "Parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), health(other.health), energy(other.energy), damage(other.damage) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->health = other.health;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (health > 0 && energy > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
        energy--;
    } else {
        std::cout << "Not enough energy or health to attack" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > health) {
        health = 0;
    } else {
        health -= amount;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (health > 0 && energy > 0) {
        health += amount;
        energy--;
        std::cout << "ClapTrap " << name << " repairs " << amount << " hit points! Remaining hit points: " << health << ", remaining energy points: " << energy << std::endl;
    } else {
        std::cout << "Not enough energy or health to repair" << std::endl;
    }
}