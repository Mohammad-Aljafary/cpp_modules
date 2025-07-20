# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include "Contact.hpp"

class PhoneBook {
    public:
        Contact contacts[8];
        void addContact();
        void searchContact();
        void exitPhoneBook();
};

#endif