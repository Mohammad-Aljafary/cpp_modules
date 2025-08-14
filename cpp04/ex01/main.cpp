#include "Brain.hpp"

int main() {
    // Create a Dog and a Cat
    Dog dog("Buddy", 3);
    Cat cat("Whiskers", 2);

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

    return 0;
}