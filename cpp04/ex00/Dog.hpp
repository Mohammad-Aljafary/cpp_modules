#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    private:
        std::string name;
        int age;

    public:
        Dog();
        Dog(std::string name, int age);
        Dog(const Dog& obj);
        ~Dog();
        Dog& operator=(const Dog& obj);

        void makeSound() const;
        const std::string& getType() const;
};