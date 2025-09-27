#include "Dog.hpp"


Dog::Dog() : name(""), brain(new Brain()), age(0) {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(std::string name, int age)
: name(name), brain(new Brain()), age(age) {
type = "Dog";
std::cout << "Dog created with name and age\n";
}

Dog::Dog(const Dog& obj)
: Animal(obj), name(obj.name), brain(new Brain(*obj.brain)), age(obj.age) {
std::cout << "Dog copied\n";
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

Dog& Dog::operator=(const Dog& obj) {
    if (this != &obj) {
        Animal::operator=(obj);
        name = obj.name;
        age = obj.age;
        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}

const std::string& Dog::getType() const {
    return type;
}

void Dog::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
