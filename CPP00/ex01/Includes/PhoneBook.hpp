#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"


class PhoneBook {
    
    private:
        Contact _contacts[8];
		int		_index;
		void 	_getContact(void);
    
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void addContact(void);
		void displayBook(void);
};

#endif
