#include "../Includes/Contact.hpp"

Contact::Contact(void) {
	this->_firstName = "";
    return ;
};

Contact::~Contact(void) {
    return ;
};

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //
void Contact::_displayCol(std::string str) {

	if (str.size() > 10) {
		for (size_t i = 0; i < 9; i++) {
			std::cout << str[i]; 	
		}
		std::cout << ".";
	}
	else {
		for (size_t i = 0; i < 10 - str.size(); i++) {
			std::cout << " ";
		}
		std::cout << str;
	}
};

std::string Contact::_addField(std::string displayMessage) {
	
	std::string input;

	while (1) {	
		std::cout << displayMessage;
		std::getline(std::cin, input);
		if (std::cin.eof() == 1)
			exit(1);
		if (input.compare("") != 0) {
			break ;
		}
	}
	return (input);
};

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //
void Contact::createContact(void) {

	this->_firstName = this->_addField("	>Enter first name: ");
	this->_lastName = this->_addField("	>Enter last name: ");
	this->_nickName = this->_addField("	>Enter nickname: ");
	this->_phoneNumber = this->_addField("	>Enter phone number: ");
	this->_darkestSecret = this->_addField("	>Enter darkest secret: ");
};

void Contact::displayContact(void) {
	
	std::cout << "____CONTACT INFORMATION____" << std::endl;
	std::cout << " ->First name: " << this->_firstName << std::endl;
	std::cout << " ->Last name: " << this->_lastName << std::endl;
	std::cout << " ->Nickname: " << this->_nickName << std::endl;
	std::cout << " ->Phone number: " << this->_phoneNumber << std::endl;
	std::cout << " ->Darkest Secret: " << this->_darkestSecret << std::endl;
}

int Contact::isEmpty(void) {
	if (this->_firstName == "") {
		return (1);
	}
	else {
		return (0);
	}
}

void Contact::displayBookInfo(void) {
	_displayCol(this->_firstName);
	std::cout << "|";
	_displayCol(this->_lastName);
	std::cout << "|";
	_displayCol(this->_nickName);
	std::cout << "|";
	std::cout << std::endl;
};
