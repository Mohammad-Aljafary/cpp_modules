#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
    std::string type;

    public:
    virtual void makeSound() const = 0;
    virtual const std::string& getType() const;
    virtual ~Animal();
    Animal();
    Animal(const Animal& obj);
    Animal& operator=(const Animal& obj);
    void setType(const std::string& type);

};