#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int PhoneBook::validInput(std::string str, int flag)
{
    for (int i = 0; str[i]; i++) {
        if (flag && !isalpha(str[i]))
            return 0;
        if (!flag && !isdigit(str[i]))
            return 0;
    }
    return 1;
}

std:: string PhoneBook::readInput(std::string str, int alpha)
{
    std::string input; 
    std:: cout << "Enter " << str << ": ";
    std::getline(std:: cin, input);

    if (input.empty())
    {
        std::cerr << "Can't have empty field" << std:: endl;
        return "";
    }
    if (!validInput(input, alpha))
    {
        std::cerr << "Invalid " << (alpha ? "character" : "number") << " in field" << std::endl;
        return "";
    }
    return input;
}