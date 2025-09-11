#include "PhoneBook.hpp"

void PhoneBook::searchContact() {
    if (numOfContact == 0) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < numOfContact; i++) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
    }
	std::string input = searchIndex();
    if (input.empty()) return;
    int index = std::atoi(input.c_str()) - 1;
    if (index < 0 || index >= numOfContact) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::addContact() {
    static int index = 0;

    std::string firstName = readInput("First Name", 1);
    if (firstName.empty()) return "";
	else if (firstName == "EXIT1") return "EXIT1";

    std::string lastName = readInput("Last Name", 1);
    if (lastName.empty()) return "";
	else if (lastName == "EXIT1") return "EXIT1";

    std::string nickName = readInput("Nickname", 1);
    if (nickName.empty()) return "";
	else if (nickName == "EXIT1") return "EXIT1";

    std:: string phoneNumber  = readInput("Phone number", 0);
    if (phoneNumber.empty()) return "";
	else if (phoneNumber == "EXIT1") return "EXIT1";

    std::cout << "Enter Darkest Secret: ";
    std::string secret;
    if (!std::getline(std::cin, secret))
	{
		std::cout << std::endl;
		return "EXIT1";
	}
    if (secret.empty()) {
        std::cerr << "Can't have empty field" << std::endl;
        return "EXIT1";
    }

    contacts[index].setFirstName(firstName);
    contacts[index].setLastName(lastName);
    contacts[index].setNickName(nickName);
    contacts[index].setPhoneNumber(phoneNumber);
    contacts[index].setDarkestSecret(secret);

    if (numOfContact < 8)
        numOfContact++;

    index = (index + 1) % 8;
	return "";
}

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

std:: string PhoneBook::readInput(std::string str, int alpha)
{
    std::string input;
    std:: cout << "Enter " << str << ": ";
    if (!std::getline(std:: cin, input))
    {
		std::cout << std::endl;
		return "EXIT1";
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
