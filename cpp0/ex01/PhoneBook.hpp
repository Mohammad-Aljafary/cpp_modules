# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
#include "Contact.hpp"


#define MAX_CONTACTS 8

class PhoneBook {
	private:
	Contact contacts[MAX_CONTACTS];
	int numOfContact;

    public:
        std::string addContact();
        void searchContact();
        std::string truncate(const std::string& str);
        std:: string readInput(std:: string str, int alpha);
        std::string searchIndex();
		void setNumOfContact(int n);
};

#endif
