#include "Form.hpp"

Form::Form(void): _name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
}
Form::Form(std::string const name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const &copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	this->_signed = copy._signed;
}

Form::~Form(void) {}

Form&	Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool		Form::getSigned(void) const
{
	return this->_signed;
}

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

int			Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int			Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::ostream&	operator<<(std::ostream &out, Form const &rhs)
{
	out << "Form name: " << rhs.getName() << std::endl
		<< "Status: " << (rhs.getSigned() ? "signed" : "unsigned") << std::endl
		<< "Grade to singed: " << rhs.getGradeToSign() << std::endl
		<< "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (out);
}