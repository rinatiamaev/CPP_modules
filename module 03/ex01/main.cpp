#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scavtrap("Han Solo");
    scavtrap.attack("Dart wader");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(7);
    scavtrap.guardGate();

    return 0;
}
