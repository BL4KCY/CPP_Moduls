#include "AForm.hpp"

AForm::AForm(void)
: _name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
}
AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute, std::string const target)
:_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
	this->_target = target;
}

AForm::AForm(AForm const &copy)
: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	this->_signed = copy._signed;
	this->_target = copy._target;
}

AForm::~AForm(void) {}

AForm&	AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

std::string	AForm::getTarget(void) const
{
	return this->_target;
}

bool		AForm::getSigned(void) const
{
	return this->_signed;
}

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

int			AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int			AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::ostream&	operator<<(std::ostream &out, AForm const &rhs)
{
	out << "AForm name: " << rhs.getName() << std::endl
		<< "AForm target: " << rhs.getTarget() << std::endl
		<< "Status: " << (rhs.getSigned() ? "signed" : "unsigned") << std::endl
		<< "Grade to singed: " << rhs.getGradeToSign() << std::endl
		<< "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (out);
}