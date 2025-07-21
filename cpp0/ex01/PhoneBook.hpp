# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
#include "Contact.hpp"

class PhoneBook {
    public:
        Contact contacts[8];
        int numOfContact;
        void addContact();
        void searchContact();
        void exitPhoneBook(int flag);
        std::string truncate(const std::string& str);
};

#endif