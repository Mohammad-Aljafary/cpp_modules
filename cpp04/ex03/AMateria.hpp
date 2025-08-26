#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
   protected:
    std::string type;

    public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& obj);
    virtual ~AMateria();
    AMateria& operator=(const AMateria& obj);
    const std::string& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target) const = 0;
};