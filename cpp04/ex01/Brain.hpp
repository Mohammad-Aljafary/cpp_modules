#pragma once

#include <iostream>
#include <string.h>

class Brain 
{
    private:
    std::string ideas[100];

    public:
    Brain();
    void operator=(Brain& obj);
    virtual ~Brain();

};
