#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : brain(new Brain()), age(0) {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(std::string name, int age) 
    : name(name), brain(new Brain()), age(age) {
    type = "Cat";
    std::cout << "Cat created with name and age\n";
}

Cat::Cat(const Cat& obj) 
    : Animal(obj), name(obj.name), brain(new Brain(*obj.brain)), age(obj.age) {
    std::cout << "Cat copied\n";
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed\n";
}

Cat& Cat::operator=(const Cat& obj) {
    if (this != &obj) {
        Animal::operator=(obj);
        name = obj.name;
        age = obj.age;
        *brain = *obj.brain; // deep copy
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

const std::string& Cat::getType() const {
    return type;
}

void Cat::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
