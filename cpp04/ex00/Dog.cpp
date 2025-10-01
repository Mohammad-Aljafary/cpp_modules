#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj) {
    std::cout << "Dog copy constructor called for " << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    if (this == &obj) {
        return *this;
    }
    Animal::operator=(obj);
    std::cout << "Dog assignment operator called for " << std::endl;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog says: Woof!" << std::endl;
}

const std::string& Dog::getType() const {
    return this->type;
}

