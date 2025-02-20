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
    std::string getFirstName();
    void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif