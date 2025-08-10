#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    private:
        std::string name;
        int age;

    public:
        Cat();
        Cat(std::string name, int age);
        Cat(const Cat& obj);
        ~Cat();
        Cat& operator=(const Cat& obj);

        void makeSound() const;
        const std::string& getType() const;
};