#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog Copy Constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy Assignment called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "GAV! GAV!" << std::endl;
}
