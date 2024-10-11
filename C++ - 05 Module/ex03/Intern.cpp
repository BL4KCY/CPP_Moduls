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
	uint16_t	index = 3;

	index = (name == "ShrubberyCreationForm") ? 0 : index;
	index = (name == "RobotomyRequestForm") ? 1 : index;
	index = (name == "PresidentialPardonForm") ? 2 : index;

	(index == 3) ? throw std::invalid_argument("Invalid Form Name"):0;

	AForm*		forms[] = 
	{
		new	ShrubberyCreationForm(target),
		new	RobotomyRequestForm(target),
		new	PresidentialPardonForm(target)
	};

	for (int i = 0 ; i < 3; i++) if (forms[i] != forms[index]) delete forms[i];
	return (forms[index]);
}
		