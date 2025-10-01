#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal parameterized constructor called for " << type << std::endl;
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

void Animal::makeSound() const {
    std::cout << "Animal makes a sound!" << std::endl;
}

const std::string& Animal::getType() const {
    return this->type;
}