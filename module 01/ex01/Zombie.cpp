#include "Zombie.hpp"

void Zombie::setZombieName(const std::string& name){
    this->name = name;
}
std::string Zombie::getZombieName(){
    return name;
}
void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(){}
Zombie::~Zombie(){
    std::cout<< name << ": Zombie destroyed\n";
}