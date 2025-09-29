#include "ScalarConverter.hpp"

void  convertedChar(const std::string& literal) {

    int num = std::stoi(literal);
    if (num < 0 || num > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(num);
    if (isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void convertedInt (const std::string& literal) {
    std::string str = literal;
    while (str[0] == ' ' || (str[0] >= 9 && str[0] <= 13))
        str.erase(0, 1);
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != '\0' && str[i] != '.' && str[i] != 'f') {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    double value = std::stod(literal);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int num = static_cast<int>(value);
    std::cout << "int: " << num << std::endl;
}

void convertedFloat (const std::string& literal) {
    std::string str = literal;
    str.find('f') != std::string::npos ? str.erase(str.find('f')) : str;

    str.find('.') == std::string::npos ? str.append(".0") : str;
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
        {
            std::cout << "float: impossible" << std::endl;
            return;
        }
        i++;
    }
    double num = std::stod(str);
    if (num < std::numeric_limits<float>::min() || num > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    std::cout << "float: " << num << "f" << std::endl;
}

void convertedDouble (const std::string& literal) {
    std::string str = literal;
    str.find('f') != std::string::npos ? str.erase(str.find('f')) : str;

    str.find('.') == std::string::npos ? str.append(".0") : str;
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
        {
            std::cout << "double: impossible" << std::endl;
            return;
        }
        i++;
    }
    double num = std::stod(str);
    if (num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "double: " << num << std::endl;
}