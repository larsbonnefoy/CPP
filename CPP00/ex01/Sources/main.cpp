#include "../Includes/Contact.hpp"
#include "../Includes/PhoneBook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook PhoneBook;
    
    while (1)
    {
        std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof() == 1)
			exit(1);
		if (cmd.compare("ADD") == 0)
            PhoneBook.addContact();
        else if (cmd.compare("SEARCH") == 0)
            PhoneBook.displayBook();
        else if (cmd.compare("EXIT") == 0) {
            break;
        }
        else {
            std::cout << "Unvalid command, valid commands are: " << std::endl; 
            std::cout << "ADD" << std::endl << "SEARCH" << std::endl << "EXIT" << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    } 
	return (0);
}
