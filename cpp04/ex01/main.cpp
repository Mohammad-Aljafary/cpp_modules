#include "Brain.hpp"

int main() {
    // Create a Dog and a Cat
    Dog *dog2 = new Dog();
    Dog *dog3 = new Dog();
    dog2->setBrainIdea(0, "I want to play!");
    *dog3 = *dog2;
    std::cout << dog3->getBrainIdea(0) << std::endl;

    Dog dog;
    Cat cat;

    // Set some ideas in their brains
    dog.setBrainIdea(0, "Chase the ball");
    dog.setBrainIdea(1, "Bark at strangers");
    
    cat.setBrainIdea(0, "Climb the tree");
    cat.setBrainIdea(1, "Catch the mouse");

    // Retrieve and print the ideas
    std::cout << "Dog's idea 0: " << dog.getBrainIdea(0) << std::endl;
    std::cout << "Dog's idea 1: " << dog.getBrainIdea(1) << std::endl;

    std::cout << "Cat's idea 0: " << cat.getBrainIdea(0) << std::endl;
    std::cout << "Cat's idea 1: " << cat.getBrainIdea(1) << std::endl;
    delete dog2;
    delete dog3;
    return 0;
}