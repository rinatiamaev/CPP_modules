#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("Dart Wader");
    ClapTrap claptrap2 = claptrap1;
    ClapTrap claptrap3;
    claptrap3 = claptrap1;

    claptrap1.attack("Joda");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);
    claptrap1.takeDamage(10);
    claptrap1.attack("Han Solo");
    claptrap1.beRepaired(5);

    return 0;
}
