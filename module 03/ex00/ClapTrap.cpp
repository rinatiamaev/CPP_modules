#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string& name){

}
ClapTrap::ClapTrap(const ClapTrap& other){
    this->name = other.name;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if (this != &other)
        this->name = other.name;
    return(*this);
}
ClapTrap::~ClapTrap(){}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap "<< name << " attacks" << target << ", causing " << damage << "points of damage!"
}
void ClapTrap::takeDamage(unsigned int amount){

}
void ClapTrap::beRepaired(unsigned int amount){

}