#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
   public:
    Cure();
    Cure(const Cure& obj);
    ~Cure();
    Cure& operator=(const Cure& obj);
    AMateria* clone() const;
    virtual void use(ICharacter& target) const;
};