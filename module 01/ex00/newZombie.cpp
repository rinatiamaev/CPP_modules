#include "Zombie.hpp"
#include <exception>

/*Creating zombie in heap*/

Zombie* newZombie(std::string name){
    try{
        Zombie* zombie = new Zombie();
        zombie->setZombieName(name);
        return (zombie);
    }
    catch (const std::bad_alloc& e){
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return (nullptr);
    }
}