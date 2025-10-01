#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Dog : public Animal {
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& obj);
        ~Dog();
        Dog& operator=(const Dog& obj);

        void makeSound() const;
        const std::string& getType() const;
        void setBrainIdea(int index, const std::string& idea);
        std::string getBrainIdea(int index) const;
};