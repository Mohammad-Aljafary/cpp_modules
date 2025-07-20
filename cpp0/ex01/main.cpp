# include "PhoneBook.hpp"

void PhoneBook::exitPhoneBook(){
    
}

void PhoneBook::searchContact(){

}

void PhoneBook:: addContact(){
    static int index = 0;
    
    std::cout << "Enter First name: ";
    std::cin >> contacts[index].firstName;
    
    std::cout << "Enter Last name: ";
    std::cin >> contacts[index].lastName;

    std:: cout << "Enter Nickname: ";
    std:: cin >> contacts[index].nickname;

    std:: cout << "Enter PhoneNumber: ";
    std:: cin >> contacts[index].phoneNumber;

    std:: cout << "Enter Darkest secret: ";
    std:: cin >> contacts[index].darkestSecret;
    index++;
    if (index == 7)
        index = 0;
}

int main() {
    PhoneBook phoneBook;

    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            phoneBook.exitPhoneBook();
            break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}