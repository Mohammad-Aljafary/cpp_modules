#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {
    private:
        bool gateKeeperMode;


    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& obj);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& obj);
        
        void attack(const std::string& target);
        void guardGate();
};