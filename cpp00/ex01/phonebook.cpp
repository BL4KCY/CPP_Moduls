#include "phonebook.hpp"

// add a new contact to the phonebook
void	PhoneBook::add(void)
{
	std::cout << GREEN << "ADD:" << END << std::endl;
	Contact	tmp;

	// std::string	FirstName;
	std::cout << "First Name: ";
	std::getline(std::cin, tmp.FirstName);
	if (tmp.FirstName.empty())
	{
		std::cout << "Error: First Name must be filled." << std::endl;
		return;
	}

	// std::string	LastName;
	std::cout << "Last Name: ";
	std::getline(std::cin, tmp.LastName);
	if (tmp.LastName.empty())
	{
		std::cout << "Error: Last Name must be filled." << std::endl;
		return;
	}

	// std::string	NickName;
	std::cout << "Nick Name: ";
	std::getline(std::cin, tmp.NickName);
	if (tmp.NickName.empty())
	{
		std::cout << "Error: Nick Name must be filled." << std::endl;
		return;
	}

	// std::string	PhoneNumber;
	std::cout << "Phone Number: ";
	std::getline(std::cin, tmp.PhoneNumber);
	if (tmp.PhoneNumber.empty())
	{
		std::cout << "Error: Phone Number must be filled." << std::endl;
		return;
	}

	// std::string	DarkestSecret;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, tmp.DarkestSecret);
	if (tmp.DarkestSecret.empty())
	{
		std::cout << "Error: Darkest Secret must be filled." << std::endl;
		return;
	}

	// add contact to phonebook
	for (int i = 0; i < 8; i++)
	{
		// if slot is empty, add contact
		if (contact[i].FirstName.empty())
		{
			contact[i] = tmp;
			if (7 != size)
				size++;
			break;
		}
		// if phonebook is full, shift all contacts up by one
		if (i == 7)
		{
			static int j = 0;
			contact[j++] = tmp;
			(7 == j) ? j = 0: j;
			if (7 != size)
				size++;
		}
	}
}

PhoneBook::PhoneBook(void)
{
	size = (-1);
}

// if the string is longer than 10 characters, replace the 10th character with a '.'
std::string MyCharOffset(std::string str)
{
	std::string	CopyStr;
	CopyStr = str;
	if (10 < str.length())
		CopyStr.replace(9, CopyStr.length(), ".");
	return (CopyStr);
}

// search for a contact in the phonebook
void	PhoneBook::search(void)
{
	std::string	input;
	int			index;

	std::cout << YELLOW << "SEARCH:" << END << std::endl;
	// if phonebook is empty, print error message
	if (size < 0)
	{
		std::cout << "Phonebook is empty!!" << std::endl;
		return;
	}
	for (int i = 0; i <= size; i++)
	{
		std::cout << std::right;
		std::cout << std::setw(MAX_FIELD_SIZE) << i << "|";
		std::cout << std::setw(MAX_FIELD_SIZE) << MyCharOffset(contact[i].FirstName) << "|";
		std::cout << std::setw(MAX_FIELD_SIZE) << MyCharOffset(contact[i].LastName) << "|";
		std::cout << std::setw(MAX_FIELD_SIZE) << MyCharOffset(contact[i].NickName) << std::endl;
	}
	while (1)
	{
		std::cout << "Enter index of contact to show their more informations: ";
		std::getline(std::cin, input);
		// if user presses ctrl+d, exit program
		if (std::cin.eof())
			exit(0);
		// if input is not a number, print error message
		if (strspn(input.c_str(), "0123456789") != input.length())
		{
			std::cout << "please Enter ONLY DIGITS !!" << std::endl;
			continue;
		}
		index = atoi(input.c_str());
		// if input is out of range, print error message
		if (!(index <= size && index >= 0))
		{
			std::cout << "Your input out of range!!" << std::endl;
			continue;
		}
		break;
	}
	// print contact information
	std::cout << GREEN << "___________________Contact information___________________" << END << std::endl;
	std::cout << RED << "First name   : " << YELLOW << contact[index].FirstName << std::endl;
	std::cout << RED << "Last name    : " << YELLOW << contact[index].LastName << std::endl;
	std::cout << RED << "Nick name    : " << YELLOW << contact[index].NickName << std::endl;
	std::cout << RED << "Phone number : " << YELLOW << contact[index].PhoneNumber << std::endl;
	std::cout << RED << "Darest secret: " << YELLOW << contact[index].DarkestSecret << std::endl;
	std::cout << END;
}
