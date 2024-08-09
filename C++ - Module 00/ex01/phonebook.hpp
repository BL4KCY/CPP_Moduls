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
#include <cstring>
#include <string>
#include <cstdlib>

#define MAX_CONTACTS 8
#define MAX_FIELD_SIZE 10

// colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define END "\033[0m"

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
	Contact	contact[MAX_CONTACTS];
	short	size;

public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
};

