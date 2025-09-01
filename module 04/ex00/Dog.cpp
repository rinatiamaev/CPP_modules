#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog Constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy Constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy Assignment Operator called!" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "GAV! GAV!" << std::endl;
}
