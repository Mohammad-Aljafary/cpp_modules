#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type) {
    std::cout << "Animal copy constructor called for " << type << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << type << " destroyed!" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
    if (this == &obj) {
        return *this;
    }
    this->type = obj.type;
    std::cout << "Animal assignment operator called for " << type << std::endl;
    return *this;
}
void Animal::setType(const std::string& type) {
    this->type = type;
}

const std::string& Animal::getType() const {
    return type;
}