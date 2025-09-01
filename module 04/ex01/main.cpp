#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Basic polymorphism test ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n=== Array of Animals test ===" << std::endl;
	Animal* animals[6];
	for (int k = 0; k < 3; ++k) {
		animals[k] = new Dog();
	}
	for (int k = 3; k < 6; ++k) {
		animals[k] = new Cat();
	}

	for (int k = 0; k < 6; ++k) {
		animals[k]->makeSound();
	}

	for (int k = 0; k < 6; ++k) {
		delete animals[k];
	}

	std::cout << "\n=== Deep copy test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love Helsinki!");
	dog1.getBrain()->setIdea(1, "Go to Japan!");

	std::cout << "\nCreating copy of dog1..." << std::endl;
	Dog dog2 = dog1;

	std::cout << "\nOriginal dog brain ideas:" << std::endl;
	std::cout << "Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;

	std::cout << "\nCopied dog brain ideas:" << std::endl;
	std::cout << "Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;

	dog1.getBrain()->setIdea(0, "I prefer cats now!");

	std::cout << "\nAfter modifying original dog brain:" << std::endl;
	std::cout << "Original Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\nBrain address comparison (should be different):" << std::endl;
	std::cout << "dog1 brain: " << dog1.getBrain() << std::endl;
	std::cout << "dog2 brain: " << dog2.getBrain() << std::endl;

	dog1.makeSound();
	dog2.makeSound();

	return (0);
}
