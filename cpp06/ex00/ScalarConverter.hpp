#pragma once

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
    
    public:
        static void convert(const std::string& literal);
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
};

void convertedChar(const std::string& literal);
void convertedInt(const std::string& literal);
void convertedFloat (const std::string& literal);
void convertedDouble (const std::string& literal);

