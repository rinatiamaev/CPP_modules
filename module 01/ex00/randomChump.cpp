#include "Zombie.hpp"

/*Creating zombie in stack*/

void randomChump(std::string name){
    Zombie zombie;
    zombie.setZombieName(name);
    zombie.announce();
}