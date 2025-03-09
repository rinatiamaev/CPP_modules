#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap fragtrap("Sky Walker");
    fragtrap.attack("Joda");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys();
    return 0;
}
