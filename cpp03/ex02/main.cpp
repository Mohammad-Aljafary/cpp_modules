#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap("ClapTrap");
    claptrap.attack("target1");
    claptrap.beRepaired(5);
    claptrap.takeDamage(3);

    ScavTrap scavtrap("ScavTrap");
    scavtrap.attack("target2");
    scavtrap.guardGate();

    FragTrap fragtrap("FragTrap");
    fragtrap.attack("target3");
    fragtrap.highFivesGuys();

    return 0;
}