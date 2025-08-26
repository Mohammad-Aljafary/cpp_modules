#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;inventory
    AMateria* [4];
    int inventoryCount;

public:
    Character();
    Character(const std::string& name);
    Character(const Character& obj);
    ~Character();
    Character& operator=(const Character& obj);
    const std::string& getName() const;    
    void equip(AMateria* m);               
    void unequip(int idx);                 
    void use(int idx, ICharacter& target);
};
