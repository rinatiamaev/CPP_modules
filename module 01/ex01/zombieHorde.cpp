#include "Zombie.hpp"

/*Creating horde of zombies in heap*/

Zombie* zombieHorde(int N, std::string name){
    if (N <= 0)
        return (nullptr);
    try{
        Zombie* horde = new Zombie[N];
        for (int i = 0; i < N; i++)
        {
            horde[i].setZombieName(name);
        }
        return (horde);
    }
    catch(const std::bad_alloc& e){
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return (nullptr);
    }
}