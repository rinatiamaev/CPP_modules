#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap instance
    ClapTrap claptrap1("Darth Wader");

    // Display initial state
    std::cout << "Initial state of ClapTrap:" << std::endl;
    claptrap1.attack("Obi Wan");
    claptrap1.takeDamage(3);
    claptrap1.beRepaired(5);

    // Create another ClapTrap instance using copy constructor
    ClapTrap claptrap2(claptrap1);

    // Display state after copy
    std::cout << "State of ClapTrap after copy:" << std::endl;
    claptrap2.attack("Han Solo");
    claptrap2.takeDamage(2);
    claptrap2.beRepaired(4);

    // Create another ClapTrap instance using assignment operator
    ClapTrap claptrap3;
    claptrap3 = claptrap1;

    // Display state after assignment
    std::cout << "State of ClapTrap after assignment:" << std::endl;
    claptrap3.attack("Yoda");
    claptrap3.takeDamage(1);
    claptrap3.beRepaired(3);

    return 0;
}