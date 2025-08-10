#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap {
    private:
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& obj);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& obj);

        void attack(const std::string& target);
        void highFivesGuys();
};