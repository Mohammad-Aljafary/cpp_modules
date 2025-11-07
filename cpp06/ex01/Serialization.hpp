#pragma once 

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serialization {

    private:
        Serialization();
        Serialization(const Serialization&);
        Serialization& operator=(const Serialization&);
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serialization();
};