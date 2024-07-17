#include "phonebook.hpp"
#include "phonebook.hpp"

int main(void)
{
	PhoneBook	phoneb;
	std::string	input;
	while (true)
	{
		std::cout << "Your options: \"ADD, SEARCH, EXIT\"" << std::endl;
		std::cout << "Please Enter you option: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phoneb.add();
		else if (input == "SEARCH")
			phoneb.search();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Wrong optins!!" << std::endl;
	}
}
