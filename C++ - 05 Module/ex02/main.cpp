#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat				bureaucrat("bureaucrat", 25);
	
		ShrubberyCreationForm	form1("home");
		RobotomyRequestForm		form2("robot");
		PresidentialPardonForm	form3("person");

		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);

		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);

		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
