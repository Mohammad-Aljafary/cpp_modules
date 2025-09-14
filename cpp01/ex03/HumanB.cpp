#include "HumanB.hpp"


HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setType( Weapon* weapon) {
    this->weapon = weapon;
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}
