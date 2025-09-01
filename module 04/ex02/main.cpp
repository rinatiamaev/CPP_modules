#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Testing Abstract AAnimal Class ===" << std::endl;

	//creating Dogs and Cats use AAnimal pointers
	std::cout << "\n--- Creating Animals through base class pointers ---" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	std::cout << "\n--- Array of Abstract Animals ---" << std::endl;
	AAnimal* animals[4];
	for (int k = 0; k < 2; ++k) {
		animals[k] = new Dog();
	}
	for (int k = 2; k < 4; ++k) {
		animals[k] = new Cat();
	}

	for (int k = 0; k < 4; ++k) {
		std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
		animals[k]->makeSound();
	}

	for (int k = 0; k < 4; ++k) {
		delete animals[k];
	}

	std::cout << "\n--- Testing Deep Copy with Abstract Base ---" << std::endl;
	Dog original;
	Dog copy = original;

	std::cout << "Original: ";
	original.makeSound();
	std::cout << "Copy: ";
	copy.makeSound();

	std::cout << "\n=== Abstract class test completed ===" << std::endl;

	return (0);
}
