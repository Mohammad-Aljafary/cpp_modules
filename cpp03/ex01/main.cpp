#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap1("Scavenger");
    ScavTrap scavTrap2;

    scavTrap1.attack("target1");
    scavTrap2.attack("target2");

    scavTrap1.guardGate();
    scavTrap2.guardGate();

    ScavTrap scavTrap3 = scavTrap1; // Using copy constructor
    scavTrap3.attack("target3");

    ScavTrap scavTrap4;
    scavTrap4 = scavTrap2; // Using assignment operator
    scavTrap4.attack("target4");

    return 0;
}