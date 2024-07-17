/*
 * author: bl4kcy
 * description: This program is a simple phonebook application that can store up to 8 contacts.
 * Each contact has a first name, last name, nickname, login, postal address, email address, phone number, and birthday date.
 * The user can add a new contact, search for a contact, or exit the program.
 * usage: ./phonebook
 */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
public:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
};

class PhoneBook
{
private:
	Contact	contact[8];
	unsigned short	size;

public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
	void	exit(void);
};

