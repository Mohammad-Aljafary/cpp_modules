#pragma once

#include <iostream>

class Weapon {
    private:
    std::string type;

    public:
    std::string getType() const;
    void setType(const std:: string& type);
    Weapon(std:: string type);
    Weapon();
};
