#include "phonebook.hpp"

// add a new contact to the phonebook
void	PhoneBook::add(void)
{
	std::cout << "add:" << std::endl;
	bool	fill_all = true;

	Contact	tmp;
	// std::string	FirstName;
	std::cout << "First Name: ";
	std::getline(std::cin, tmp.FirstName);
	tmp.FirstName.empty() ? fill_all = false : 0;

	// std::string	LastName;
	std::cout << "Last Name: ";
	std::getline(std::cin, tmp.LastName);
	tmp.LastName.empty() ? fill_all = false : 0;

	// std::string	NickName;
	std::cout << "Nick Name: ";
	std::getline(std::cin, tmp.NickName);
	tmp.NickName.empty() ? fill_all = false : 0;

	// std::string	PhoneNumber;
	std::cout << "Phone Number: ";
	std::getline(std::cin, tmp.PhoneNumber);
	tmp.PhoneNumber.empty() ? fill_all = false : 0;

	// std::string	DarkestSecret;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, tmp.DarkestSecret);
	tmp.DarkestSecret.empty() ? fill_all = false : 0;

	// check if all fields are filled
	if (fill_all)
	{
		// add contact to phonebook
		for (int i = 0; i < 8; i++)
		{
			// if slot is empty, add contact
			if (contact[i].FirstName.empty())
			{
				contact[i] = tmp;
				if (8 != size)
					size++;
				break;
			}
			// if phonebook is full, shift all contacts up by one
			if (i == 7)
			{
				static int j = 0;
				contact[j++] = tmp;
				(7 == j) ? j = 0: j;
				if (8 != size)
					size++;
			}
		}
	}
	else
	{
		// if not all fields are filled, print error message
		std::cout << "Error: All fields must be filled." << std::endl;
	}
}

PhoneBook::PhoneBook(void)
{
	size = 0;
}

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
	for (int i = 0; i < size; i++)
	{
		std::cout << std::right;
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << MyCharOffset(contact[i].FirstName) << "|";
		std::cout << std::setw(10) << MyCharOffset(contact[i].LastName) << "|";
		std::cout << std::setw(10) << MyCharOffset(contact[i].NickName) << std::endl;
	}
}
