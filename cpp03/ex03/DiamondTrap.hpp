#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>
#include <utility>

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& obj);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& obj);

        void attack(const std::string& target);
        void whoAmI() const;
};
