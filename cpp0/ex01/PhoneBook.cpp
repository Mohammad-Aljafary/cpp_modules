#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int validNumber(std::string str)
{
	for (int i = 0; str[i]; i++) {
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int validStr(std::string str)
{
	for (int i = 0; str[i]; i++) {
		if (!isalpha(str[i]) && !isspace(str[i]))
			return 0;
	}
	return 1;
}

std:: string PhoneBook::readInput(std::string str, int alpha)
{
    std::string input;
    std:: cout << "Enter " << str << ": ";
    if (!std::getline(std:: cin, input))
    {
		std::cout << std::endl;
		return "EXIT";
	}
    if (input.empty())
    {
        std::cerr << "Can't have empty field" << std:: endl;
        return "";
    }
	if (!alpha && !validNumber(input))
	{
		std::cerr << "Invalid " << (alpha ? "character" : "number") << " in field" << std::endl;
		return "";
	}
    if (alpha && !validStr(input))
    {
        std::cerr << "Invalid " << (alpha ? "character" : "number") << " in field" << std::endl;
        return "";
    }
    return input;
}

void PhoneBook::setNumOfContact(int n) {
	this->numOfContact = n;
}

std::string PhoneBook::searchIndex() {
	std::string input;
	std:: cout << "Enter index to view details: ";
	if (!std::getline(std:: cin, input))
	{
		std::cout << std::endl;
		return "EXIT";
	}
	if (input.empty())
		return "";
	if (!validNumber(input)) {
		std::cerr << "Invalid character in index" << std::endl;
		return "";
	}
	return input;
}
