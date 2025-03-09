#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Animal type: " << j->getType() << std::endl;
    std::cout << "Animal type: " << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    Dog dog1;
    Dog dog2 = dog1;
    dog2.makeSound();

    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    cat2.makeSound();

    delete meta;
    delete j;
    delete i;

    return 0;
}
