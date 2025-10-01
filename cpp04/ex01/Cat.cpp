#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : brain(new Brain()){
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& obj) 
    : Animal(obj), brain(new Brain(*obj.brain)){
    std::cout << "Cat copied" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    if (this != &obj) {
        Animal::operator=(obj);
        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
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
