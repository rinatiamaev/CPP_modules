#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat Constructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy Constructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy Assignment Operator called!" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "MAW! MAW!" << std::endl;
}
