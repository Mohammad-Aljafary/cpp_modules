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
    std:: cout << std::setw(10)   << "----" 
                << std:: setw(10) << " ----" 
                << std:: setw(10) << "----" 
                << std:: setw(10) << "----" << std:: endl;

    for (int i = 0; i < numOfContact; i++) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(contacts[i].firstName) << "|"
                  << std::setw(10) << truncate(contacts[i].lastName) << "|"
                  << std::setw(10) << truncate(contacts[i].nickname) << std::endl;
        std:: cout << std::setw(10)   << "----" 
        << std:: setw(10) << " ----" 
        << std:: setw(10) << "----" 
        << std:: setw(10) << "----" << std:: endl;
    }
}

int printtErr (std:: string str)
{
    int i;

    for (i = 0; str[i]; i++)
    {
        std:: cerr << "There is an Invalid Input" << std:: endl;
        return (0);
    }
    return (1);
}

int PhoneBook:: validInput(Contact contact)
{
    int i;

    if (!printtErr(contact.firstName))
        return (0);
    if (!printtErr(contact.lastName))
        return (0);
    if (!printtErr(contact.nickname))
        return (0);
    if (!printtErr(contact.darkestSecret))
        return (0);
    for (i = 0; contact.phoneNumber[i]; i++)
    {
        if (!isdigit(contact.phoneNumber[i]))
        {
            std:: cerr << "There is an Invalid Input" << std:: endl;
            return (0);
        }
    }
    return (1);
}


void PhoneBook::addContact() {
    static int index = 0;

    std::cout << "Enter First name: ";
    std::getline(std::cin, contacts[index].firstName);
    if (contacts[index].firstName.empty())
        return ;

    std::cout << "Enter Last name: ";
    std::getline(std::cin, contacts[index].lastName);
    if (contacts[index].lastName.empty())
        return ;

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, contacts[index].nickname);
    if (contacts[index].nickname.empty())
        return ;

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, contacts[index].phoneNumber);
    if (contacts[index].phoneNumber.empty())
        return ;

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, contacts[index].darkestSecret);
    if (contacts[index].darkestSecret.empty())
        return ;
    if (!validInput(contacts[index]))
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