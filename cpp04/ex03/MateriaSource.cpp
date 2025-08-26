#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : inventoryCount(0) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& obj) : inventoryCount(obj.inventoryCount) {
    for (int i = 0; i < 4; ++i) {
        if (obj.inventory[i]) {
            inventory[i] = obj.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
    if (this != &obj) {
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

void MateriaSource::learnMateria(AMateria* m) {
    if (inventoryCount < 4 && m) {
        inventory[inventoryCount++] = m;
    }
}
AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < inventoryCount; ++i) {
        if (inventory[i] && inventory[i]->getType() == type) {
            return inventory[i]->clone();
        }
    }
    return NULL;
}