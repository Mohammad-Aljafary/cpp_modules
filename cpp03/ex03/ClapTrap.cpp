#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap parameterized constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hitPoints(obj.hitPoints), energyPoints(obj.energyPoints), attackDamage(obj.attackDamage) {
    std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    if (this == &obj) {
        return *this;
    }

    name = obj.name;
    hitPoints = obj.hitPoints;
    energyPoints = obj.energyPoints;
    attackDamage = obj.attackDamage;

    std::cout << "ClapTrap assignment operator called!" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints == 0 || this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is out of energy or hit points and cannot attack!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints == 0 || this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is out of energy or hit points and cannot repair!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " has been repaired by " << amount 
              << " points! Current hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has already died!" << std::endl;
        return;
    }
    this->hitPoints -= amount;
    if (this->hitPoints <= 0) {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage and has died!" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage! Remaining hit points: " 
                  << this->hitPoints << std::endl;
    }
}


const std::string& ClapTrap::getName() const {
    return name;
}

int ClapTrap::getHitPoints() const {
    return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

void ClapTrap::setName(const std::string& newName) {
    name = newName;
}

void ClapTrap::setHitPoints(int points) {
    hitPoints = points;
}

void ClapTrap::setEnergyPoints(int points) {
    energyPoints = points;
}

void ClapTrap::setAttackDamage(int damage) {
    attackDamage = damage;
}
