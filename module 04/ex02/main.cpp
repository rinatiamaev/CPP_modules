#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    AAnimal* animals[4];
    for (int k = 0; k < 2; ++k) {
        animals[k] = new Dog();
    }
    for (int k = 2; k < 4; ++k) {
        animals[k] = new Cat();
    }

    for (int k = 0; k < 4; ++k) {
        animals[k]->makeSound();
    }

    for (int k = 0; k < 4; ++k) {
        delete animals[k];
    }

    return 0;
}
