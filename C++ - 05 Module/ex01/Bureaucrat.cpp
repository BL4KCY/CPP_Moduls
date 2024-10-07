#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("Default")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = Bureaucrat(copy.getName(), copy.getGrade());
}
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->getName() << " destroyed!" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		*this = Bureaucrat(rhs.getName(), rhs.getGrade());
    return *this;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

void Bureaucrat::incrementGrade(void)
{
	this->_grade - 1 < 1 ? throw GradeTooHighException() : this->_grade--;
}
void Bureaucrat::decrementGrade(void)
{
	this->_grade + 1 > 150 ? throw GradeTooLowException() : this->_grade++;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << "Bureaucrat name: " << rhs.getName()
		<< ", Bureaucrat grade: " << rhs.getGrade()
		<< std::endl;
	return out;
}

void		Bureaucrat::beSigned(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << form.getName() << " because "	<< e.what() << std::endl;
	}
}
