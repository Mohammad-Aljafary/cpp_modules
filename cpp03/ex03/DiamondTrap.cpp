#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), name("Default DiamondTrap") {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) :ClapTrap(obj.name + "_clap_name"), FragTrap(obj), ScavTrap(obj), name(obj.name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
    if (this == &obj) {
        return *this;
    }
    FragTrap::operator=(obj);
    ScavTrap::operator=(obj);
    this->name = obj.name;
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "DiamondTrap " << this->name << " attacks " << target 
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "DiamondTrap " << this->name << " cannot attack!" << std::endl;
    }
}

void DiamondTrap::whoAmI() const {
    std::cout << "I am " << this->name 
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
