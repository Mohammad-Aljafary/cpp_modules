#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   private:
    AMateria* inventory[4];
    int inventoryCount;

   public:
    MateriaSource();
    MateriaSource(const MateriaSource& obj);
    ~MateriaSource();
    MateriaSource& operator=(const MateriaSource& obj);
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(const std::string& type);
};