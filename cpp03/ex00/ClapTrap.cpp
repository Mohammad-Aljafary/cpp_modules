#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name){
    std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(){
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj){
    *this = obj;
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap ClapTrap::operator=(const ClapTrap& obj){
    if (this != &obj)
    {
        this->attackDamage = obj.attackDamage;
        this->energyPoints = obj.energyPoints;
        this->hitPoints = obj.hitPoints;
        this->name = obj.name;
    }
    std::cout << "assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called" << std::endl;
}

