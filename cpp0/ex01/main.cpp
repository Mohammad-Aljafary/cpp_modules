# include "PhoneBook.hpp"

void PhoneBook::exitPhoneBook(int flag){
    if (flag)
        std:: cout << std::endl;
    exit(0);
}

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}


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
                  << std::setw(10) << truncate(contacts[i].firstName) << "|"
                  << std::setw(10) << truncate(contacts[i].lastName) << "|"
                  << std::setw(10) << truncate(contacts[i].nickname) << std::endl;
    }
}

#define MAX_CONTACTS 8

void PhoneBook::addContact() {
    static int index = 0;

    std::cout << "Enter First name: ";
    if (!std::getline(std::cin, contacts[index].firstName))
        return ;

    std::cout << "Enter Last name: ";
    if (!std::getline(std::cin, contacts[index].lastName))
        return ;

    std::cout << "Enter Nickname: ";
    if (!std::getline(std::cin, contacts[index].nickname))
        return ;

    std::cout << "Enter Phone Number: ";
    if (!std::getline(std::cin, contacts[index].phoneNumber))
        return ;

    std::cout << "Enter Darkest Secret: ";
    if (!std::getline(std::cin, contacts[index].darkestSecret))
        return ;
    if (numOfContact < 8)
        numOfContact++;

    index = (index + 1) % 8;
}


int main() {
    PhoneBook phoneBook;
    phoneBook.numOfContact = 0;

    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
            phoneBook.exitPhoneBook(1);
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            phoneBook.exitPhoneBook(0);
            break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}