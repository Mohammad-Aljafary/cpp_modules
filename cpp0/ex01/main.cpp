# include "PhoneBook.hpp"

void PhoneBook::exitPhoneBook(int flag){
    if (flag)
        std:: cout << std::endl;
    exit(0);
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
    std:: cout << std::setw(10)   << "----" 
                << std:: setw(10) << " ----" 
                << std:: setw(10) << "----" 
                << std:: setw(10) << "----" << std:: endl;

    for (int i = 0; i < numOfContact; i++) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(contacts[i].firstName) << "|"
                  << std::setw(10) << truncate(contacts[i].lastName) << "|"
                  << std::setw(10) << truncate(contacts[i].nickName) << std::endl;
        std:: cout << std::setw(10)   << "----" 
        << std:: setw(10) << " ----" 
        << std:: setw(10) << "----" 
        << std:: setw(10) << "----" << std:: endl;
    }
}

void PhoneBook::addContact() {
    static int index = 0;

    std::string firstName = readInput("First Name", 1);
    if (firstName.empty()) return ;
    
    std:: string lastName = readInput("Last Name", 1);
    if (lastName.empty()) return ;
    
    std:: string nickName = readInput("Nickname", 1);
    if (nickName.empty()) return ;

    std:: string phoneNumber  = readInput("Phone number", 0);
    if (phoneNumber.empty()) return;

    std::cout << "Enter Darkest Secret: ";
    std::string secret;
    std::getline(std::cin, secret);
    if (secret.empty()) {
        std::cerr << "Can't have empty field" << std::endl;
        return;
    }

    contacts[index].firstName = firstName;
    contacts[index].lastName = lastName;
    contacts[index].nickName = nickName;
    contacts[index].phoneNumber = phoneNumber;
    contacts[index].darkestSecret = secret;

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