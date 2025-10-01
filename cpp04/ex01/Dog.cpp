#include "Dog.hpp"


Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created"<< std::endl;
}


Dog::Dog(const Dog& obj): Animal(obj), brain(new Brain(*obj.brain)) {
    std::cout << "Dog copied"<< std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed"<< std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    if (this != &obj) {
        Animal::operator=(obj);

        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
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
