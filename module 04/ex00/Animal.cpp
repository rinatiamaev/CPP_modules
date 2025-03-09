#include "Animal.hpp"

Animal::Animal() : type("Noname") {
    std::cout << "Animal Default Constructor called!" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy Constructor called!" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Copy Assignment Operator called!" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Virtual Destructor called!" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Here is a great animal sound must be produce" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
