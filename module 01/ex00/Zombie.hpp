#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
    Zombie();
    ~Zombie();
    void setZombieName(const std::string& name);
    std::string getZombieName();
    void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif