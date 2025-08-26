#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Dog : public Animal {
    private:
        std::string name;
        Brain* brain;
        int age;

    public:
        Dog();
        Dog(std::string name, int age);
        Dog(const Dog& obj);
        ~Dog();
        Dog& operator=(const Dog& obj);

        void makeSound() const;
        const std::string& getType() const;
        void setBrainIdea(int index, const std::string& idea);
        std::string getBrainIdea(int index) const;
};