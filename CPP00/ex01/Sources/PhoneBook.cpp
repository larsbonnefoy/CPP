#include "../Includes/PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook(void) {

	this->_index = 0;
    return;
};

PhoneBook::~PhoneBook(void) {
    return;
};

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //
void PhoneBook::_getContact(void) {
	
	std::string indexNumberBuffer;
	int			indexNumber;

	while (1)
	{
		std::cout << "Enter valid index number: ";
		std::getline(std::cin, indexNumberBuffer);
		if (std::cin.eof() == 1)
			exit(1);
		std::stringstream ss(indexNumberBuffer);
		ss >> indexNumber;
		if (ss.fail()) {
			std::cout << "Unvalid index" << std::endl;
		}
		if ((indexNumber >= 1 && indexNumber <= 8) && !this->_contacts[indexNumber - 1].isEmpty()) {
			this->_contacts[indexNumber - 1].displayContact();
			break;
		}
	}
}

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //
void PhoneBook::displayBook(void) {

	if (this->_contacts[0].isEmpty()) {
		std::cout << "No contacts saved in phonebook at the moment" << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].isEmpty()) {
			for (int j = 0; j < 7; j++) {
				std::cout << " ";
			}
			std::cout << i + 1 << "|";
			this->_contacts[i].displayBookInfo();	
		}
	}
	_getContact();
}

void PhoneBook::addContact(void) {

	if (this->_index >= 8)
		this->_index = 0;
    this->_contacts[this->_index].createContact();
	this->_index += 1;
};
