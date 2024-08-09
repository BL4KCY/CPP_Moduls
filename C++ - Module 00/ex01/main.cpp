#include "phonebook.hpp"
#include "phonebook.hpp"

int main(void)
{
	PhoneBook	phoneb;
	std::string	input;
	while (true)
	{
		std::cout << GREEN << "___________________COMMANDS___________________" << END << std::endl;
		std::cout << "Your options: \""
		<< GREEN << "ADD" << ", "
		<< YELLOW<< " SEARCH" <<", "
		<< RED << "EXIT"
		<< END<< "\"" << std::endl;
		std::cout << "Please Enter you option: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "ADD")
			phoneb.add();
		else if (input == "SEARCH")
			phoneb.search();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Wrong optins!!" << std::endl;
		if (std::cin.eof())
			return (0);
	}
}
