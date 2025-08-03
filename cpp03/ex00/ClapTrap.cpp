#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name){

}

ClapTrap::ClapTrap(){

}

ClapTrap::ClapTrap(const ClapTrap& obj){
    *this = obj;
}

ClapTrap ClapTrap::operator=(const ClapTrap& obj){
    if (this != &obj)
    {
        this->attackDamage = obj.attackDamage;
        this->energyPoints = obj.energyPoints;
        this->hitPoints = obj.hitPoints;
        this->name = obj.name;
    }
    return *this;
}

ClapTrap::~ClapTrap(){

}

