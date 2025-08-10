#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), gateKeeperMode(false) {
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->setName("Default ScavTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj), gateKeeperMode(obj.gateKeeperMode) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
    if (this == &obj) {
        return *this;
    }
    ClapTrap::operator=(obj);
    this->gateKeeperMode = obj.gateKeeperMode;
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target 
                  << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        std::cout << "ScavTrap " << this->getName() << " cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    this->gateKeeperMode = true;
    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode!" << std::endl;
}
