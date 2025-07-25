#pragma once

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    
    public:
        HumanB(std::string name);
        void setType(Weapon& weapon);
        void attack();
};
    