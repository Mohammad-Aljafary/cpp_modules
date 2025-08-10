#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->setName("Default FragTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
    if (this == &obj) {
        return *this;
    }
    ClapTrap::operator=(obj);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "FragTrap " << this->getName() << " attacks " << target 
                  << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        std::cout << "FragTrap " << this->getName() << " cannot attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
}


