#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type) {
    std::cout << "AMateria parameterized constructor called for type: " << type << std::endl;
}

AMateria::AMateria(const AMateria& obj) : type(obj.type) {
    std::cout << "AMateria copy constructor called for type: " << type << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria of type " << type << " destroyed!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj) {
    if (this == &obj) {
        return *this;
    }
    this->type = obj.type;
    std::cout << "AMateria assignment operator called for type: " << type << std::endl;
    return *this;
}

const std::string& AMateria::getType() const {
    return type;
}
