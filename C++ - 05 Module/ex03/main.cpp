#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat				bureaucrat("bureaucrat", 25);
	
		AForm*	form1 = Intern::makeForm("ShrubberyCreationForm", "home");
		AForm*	form2 = Intern::makeForm("RobotomyRequestForm", "robot");
		AForm*	form3 = Intern::makeForm("PresidentialPardonForm", "person");

		bureaucrat.signForm(*form1);
		bureaucrat.executeForm(*form1);

		bureaucrat.signForm(*form2);
		bureaucrat.executeForm(*form2);

		bureaucrat.signForm(*form3);
		bureaucrat.executeForm(*form3);
		
		AForm*	form4 = Intern::makeForm("Wrong form name", "car"); // should throw an error

		bureaucrat.signForm(*form4);
		bureaucrat.executeForm(*form4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
