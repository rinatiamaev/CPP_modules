#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MAW! MAW!" << std::endl;
}
