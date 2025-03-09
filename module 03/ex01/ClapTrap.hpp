#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap();                            // Default Constructor
    ClapTrap(std::string name);            // Parameterized Constructor
    ClapTrap(const ClapTrap& other);       // Copy Constructor
    ClapTrap& operator=(const ClapTrap& other); // Copy Assignment Operator
    virtual ~ClapTrap();                   // Virtual Destructor for inheritance

    // Member Functions
    virtual void attack(const std::string& target);  // Virtual to allow overriding
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
