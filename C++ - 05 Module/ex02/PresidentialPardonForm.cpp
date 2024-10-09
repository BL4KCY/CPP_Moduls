#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 72, 45, "default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
: AForm("PresidentialPardonForm", 72, 45, target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw std::logic_error(this->getName() + " Form not signed");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
