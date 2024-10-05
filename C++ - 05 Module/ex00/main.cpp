#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat hassan("hassan", 1);
		std::cout << hassan;
		hassan.decrementGrade();
		hassan.decrementGrade();
		std::cout << hassan;
		hassan.incrementGrade();
		hassan.incrementGrade();
		std::cout << hassan;
		hassan.incrementGrade(); // should throw exception (GradeTooHighException)
		std::cout << hassan; // should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat benMoussa("benMossa", 150);
		std::cout << benMoussa;
		benMoussa.incrementGrade();
		benMoussa.incrementGrade();
		std::cout << benMoussa;
		benMoussa.decrementGrade();
		benMoussa.decrementGrade();
		std::cout << benMoussa;
		benMoussa.decrementGrade(); // should throw exception (GradeTooLowException)
		std::cout << benMoussa; // should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
