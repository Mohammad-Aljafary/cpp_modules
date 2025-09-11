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
	std::string truncate(const std::string& str);
	std:: string readInput(std:: string str, int alpha);
	std::string searchIndex();

    public:
        std::string addContact();
        void searchContact();
		void setNumOfContact(int n);
};

#endif
