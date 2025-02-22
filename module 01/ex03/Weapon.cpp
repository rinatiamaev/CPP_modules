#include "Weapon.hpp"

Weapon::Weapon() : type("Unknown weapon") {}

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::Weapon(const Weapon& other) {
    *this = other;
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    type = newType;
}
