#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj) {
    std::cout << "Cat copy constructor called for " << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    if (this == &obj) {
        return *this;
    }
    Animal::operator=(obj);
    std::cout << "Cat assignment operator called for " << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat says: Meow!" << std::endl;
}

const std::string& Cat::getType() const {
    return this->type;
}
