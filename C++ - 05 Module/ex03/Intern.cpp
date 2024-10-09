#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern&	Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string const name, std::string const target)
{
	if (name == "ShrubberyCreationForm")
		return new ShrubberyCreationForm(target);
	else if (name == "RobotomyRequestForm")
		return new RobotomyRequestForm(target);
	else if (name == "PresidentialPardonForm")
		return new PresidentialPardonForm(target);
	else
		throw std::invalid_argument("Invalid Form Name");
	return NULL;
}