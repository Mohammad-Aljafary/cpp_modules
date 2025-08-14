#pragma once

#include <iostream>
#include <string.h>
#include "Cat.hpp"
#include "Dog.hpp"

class Brain {
    private:
    std::string ideas[100];

    public:
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};