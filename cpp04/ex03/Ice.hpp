#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
   public:
    Ice();
    Ice(const Ice& obj);
    ~Ice();
    Ice& operator=(const Ice& obj);
    AMateria* clone() const;
    virtual void use(ICharacter& target) const;
};