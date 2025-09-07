# include "PhoneBook.hpp"

void PhoneBook::searchContact() {
    if (numOfContact == 0) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std:: cout << std::setw(10)   << "----"
                << std:: setw(10) << " ----"
                << std:: setw(10) << "----"
                << std:: setw(10) << "----" << std:: endl;

    for (int i = 0; i < numOfContact; i++) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
        std:: cout << std::setw(10)   << "----"
        << std:: setw(10) << " ----"
        << std:: setw(10) << "----"
        << std:: setw(10) << "----" << std:: endl;
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
	else if (firstName == "EXIT") return "EXIT";
    std::string lastName = readInput("Last Name", 1);
    if (lastName.empty()) return "";

    std::string nickName = readInput("Nickname", 1);
    if (nickName.empty()) return "";
	else if (nickName == "EXIT") return "EXIT";

    std:: string phoneNumber  = readInput("Phone number", 0);
    if (phoneNumber.empty()) return "";
	else if (phoneNumber == "EXIT") return "EXIT";

    std::cout << "Enter Darkest Secret: ";
    std::string secret;
    std::getline(std::cin, secret);
    if (secret.empty()) {
        std::cerr << "Can't have empty field" << std::endl;
        return "EXIT";
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
            if (phoneBook.addContact() == "EXIT") break;
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
