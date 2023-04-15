#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

class Contact {

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

		std::string _addField(std::string displayMessage);
		void		_displayCol(std::string str);

    public:
        Contact(void);
        ~Contact(void);
        void	createContact(void);
		void	displayContact(void);
		void	displayBookInfo(void);
		int		isEmpty(void);
};

#endif
