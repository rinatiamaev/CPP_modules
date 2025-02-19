#include "Zombie.hpp"

/*Creating zombie in heap*/

Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie();
    zombie->setZombieName(name);
    return (zombie);
}