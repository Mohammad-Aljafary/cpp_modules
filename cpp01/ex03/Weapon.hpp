#pragma once

#include <iostream>

class Weapon {
    private:
    std::string type;

    public:
    std::string getType();
    void setType(std:: string type);
    Weapon(std:: string type);
    Weapon();
};