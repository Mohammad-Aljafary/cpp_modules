#pragma once

#include <iostream>

#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:

        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& obj);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& obj);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        const std::string& getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        void setName(const std::string& newName) ; 
        void setHitPoints(int points);
        void setEnergyPoints(int points);
        void setAttackDamage(int damage);
        
};
