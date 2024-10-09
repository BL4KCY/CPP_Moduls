#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 72, 45)
{
	this->_target = "default";	
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): AForm("PresidentialPardonForm", 72, 45) 
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw std::logic_error(this->getName() + " Form not signed");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
