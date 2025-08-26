#include "Character.hpp"

// Default constructor
Character::Character() : name("Unknown"), inventoryCount(0) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

// Parameterized constructor
Character::Character(const std::string& name) : name(name), inventoryCount(0)
{
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

// Copy constructor
Character::Character(const Character& obj) : name(obj.name), inventoryCount(obj.inventoryCount)
{
    for (int i = 0; i < 4; ++i) {
        if (obj.inventory[i]) {
            inventory[i] = obj.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
}

// Destructor
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

// Assignment operator
Character& Character::operator=(const Character& obj) {
    if (this != &obj) {
        name = obj.name;
        inventoryCount = obj.inventoryCount;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (obj.inventory[i]) {
                inventory[i] = obj.inventory[i]->clone();
            } else {
                inventory[i] = NULL;
            }
        }
    }
    return *this;
}

const std::string& Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (inventoryCount < 4 && m) {
        inventory[inventoryCount++] = m;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx] = NULL;
        --inventoryCount;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
