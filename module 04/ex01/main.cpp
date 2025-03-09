#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

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

    Dog dog1;
    dog1.makeSound();
    Dog dog2 = dog1;
    dog2.makeSound();

    return 0;
}
