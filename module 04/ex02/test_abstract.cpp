#include "AAnimal.hpp"

int main() {
	// This should cause a compilation error:
	// AAnimal animal; // Error: cannot declare variable 'animal' to be of abstract type 'AAnimal'
	// AAnimal* ptr = new AAnimal(); // Error: cannot allocate an object of abstract type 'AAnimal'
	std::cout << "If this compiles, the abstract test failed!" << std::endl;
	return (0);
}
