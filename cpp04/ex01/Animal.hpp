#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string name, int age);
        Animal(const Animal& obj);
        virtual ~Animal();
        Animal& operator=(const Animal& obj);

        virtual void makeSound() const;
        virtual const std::string& getType() const;
};