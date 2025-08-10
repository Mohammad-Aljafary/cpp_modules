#include "Dog.hpp"

Dog::Dog() : Animal("Dog", 0), name("Default Dog"), age(0) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name, int age) : Animal("Dog", age), name(name), age(age) {
    std::cout << "Dog parameterized constructor called for " << name << " aged " << age << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj), name(obj.name), age(obj.age) {
    std::cout << "Dog copy constructor called for " << name << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog " << name << " destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    if (this == &obj) {
        return *this;
    }
    Animal::operator=(obj);
    this->name = obj.name;
    this->age = obj.age;
    std::cout << "Dog assignment operator called for " << name << std::endl;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog " << name << " says: Woof!" << std::endl;
}

const std::string& Dog::getType() const {
    return this->type;
}

