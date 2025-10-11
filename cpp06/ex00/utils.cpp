#include "ScalarConverter.hpp"

/*
 * Converts a string literal to a char
 */
void  convertedChar(const std::string& literal) {

    std::string str = literal;
    int i = 0;
    
    int num;
    str.find('f') != std::string::npos ? str.erase(str.find('f'), 1) : str;
    while (str[i])
    {
        if (str[i] == '.' && str[i + 1] != '\0')
        {   
            if (str[i + 1] != '0')
            {
                std::cout << "char: impossible" << std::endl;
                return;
            }
        }
        i++;
    }
    std::stringstream ss(str);
    if (!(ss >> num)) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
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

/*
** Converts a string literal to an int
*/
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
    std::stringstream ss(literal);
    double value;
    if (!(ss >> value)) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int num = static_cast<int>(value);
    std::cout << "int: " << num << std::endl;
}

/*
** Converts a string literal to a float
*/

void convertedFloat (const std::string& literal) {
    std::string str = literal;

    if (str == "nan" || str == "inf" || str == "-inf")
    {
        std::cout << "float: " << str << "f" << std::endl;
        return;
    }

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
    std::stringstream ss(str);
    double num;
    if (!(ss >> num)) {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    if (num < std::numeric_limits<float>::min() || num > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    std::cout << "float: " << num << "f" << std::endl;
}

/*
** Converts a string literal to a double
*/

void convertedDouble (const std::string& literal) {
    std::string str = literal;

    if (str == "nan" || str == "inf" || str == "-inf")
    {
        std::cout << "double: " << str << std::endl;
        return;
    }

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
    std::stringstream ss(str);
    double num;
    if (!(ss >> num)) {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    std::cout << "double: " << num << std::endl;
}
