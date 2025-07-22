# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
#include "Contact.hpp"


#define MAX_CONTACTS 8

class PhoneBook {
    public:
        Contact contacts[8];
        int numOfContact;
        void addContact();
        void searchContact();
        void exitPhoneBook(int flag);
        std::string truncate(const std::string& str);
        int validInput(std:: string str, int flag);
        std:: string readInput(std:: string str, int alpha);
};

#endif