#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Brain;

class Cat : public Animal {
    private:
        Brain* brain;

    public:
        Cat();
        Cat(const Cat& obj);
        ~Cat();
        Cat& operator=(const Cat& obj);

        void makeSound() const;
        const std::string& getType() const;
        void setBrainIdea(int index, const std::string& idea);
        std::string getBrainIdea(int index) const;
};