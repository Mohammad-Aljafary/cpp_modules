# include "PhoneBook.hpp"

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

int main() {
    PhoneBook phoneBook;
    phoneBook.setNumOfContact(0);

    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			return 1;
		}
        if (command == "ADD") {
            if (phoneBook.addContact() == "EXIT1") break;
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
			break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}
