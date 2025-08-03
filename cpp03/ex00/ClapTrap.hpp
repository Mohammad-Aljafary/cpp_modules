#pragma once

#include <iostream>

class ClapTrap{
    private:
    std::string name;
    int hitPoints = 10;
    int energyPoints = 10;
    int attackDamage = 0;

    public:
    ClapTrap();
    ClapTrap(const ClapTrap& obj);
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap operator=(const ClapTrap& obj);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};