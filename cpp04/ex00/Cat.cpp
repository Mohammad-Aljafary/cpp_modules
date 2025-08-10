#include "Cat.hpp"

Cat::Cat() : Animal("Cat", 0), name("Default Cat"), age(0) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name, int age) : Animal("Cat", age), name(name), age(age) {
    std::cout << "Cat parameterized constructor called for " << name << " aged " << age << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj), name(obj.name), age(obj.age) {
    std::cout << "Cat copy constructor called for " << name << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat " << name << " destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    if (this == &obj) {
        return *this;
    }
    Animal::operator=(obj);
    this->name = obj.name;
    this->age = obj.age;
    std::cout << "Cat assignment operator called for " << name << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat " << name << " says: Meow!" << std::endl;
}

const std::string& Cat::getType() const {
    return this->type;
}
