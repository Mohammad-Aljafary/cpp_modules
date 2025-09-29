#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string& literal) {
    std::cout << "Converting literal: " << literal << std::endl;
    convertedChar(literal);
    convertedInt(literal);
    convertedFloat(literal);
    convertedDouble(literal);
}