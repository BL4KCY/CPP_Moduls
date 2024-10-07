#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form	Feedback("Foodback 1337", 10, 20);
		Form	Order("speaker Order", 49, 40);
		Bureaucrat hassan("hassan", 1);
		Bureaucrat benMoussa("benMossa", 150);
		Bureaucrat ahmed("ahmed", 50);
		std::cout << "\t\t**" << Feedback.getName() << " Form**\n" << Feedback;
		std::cout << "\t\t**" << Order.getName() << " Form**\n" << Order;
		
		// testing when the grade of the bureaucrat is high enough to sign the form
		try
		{
			std::cout << "\t\t**| test hassan |**" << std::endl;
			std::cout << hassan;
			hassan.signForm(Feedback);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\t\t**" << Feedback.getName() << " Form**\n" << Feedback;
		
		// testing when the grade of the bureaucrat is not high enough to sign the form
		try
		{
			std::cout << "\t\t**| test benMoussa |**" << std::endl;
			std::cout << benMoussa;
			benMoussa.signForm(Feedback);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\t\t**" << Feedback.getName() << " Form**\n" << Feedback;

		// testing when the grade of the bureaucrat is not high enough to sign the form
		try
		{
			std::cout << "\t\t**| test ahmed {1}|**" << std::endl;
			std::cout << ahmed;
			ahmed.signForm(Order);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\t\t**" << Order.getName() << " Form**\n" << Order;

		// testing after incrementing the grade of the bureaucrat to be able to sign the form
		try
		{
			std::cout << "\t\t**| test ahmed {2}|**" << std::endl;
			ahmed.incrementGrade();
			std::cout << ahmed;
			ahmed.signForm(Order);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\t\t**" << Order.getName() << " Form**\n" << Order;
		std::cout << std::endl << "------| end of tests |--------\n" << std::endl;

		// testing when constructing a form with a grade that is too high
		Form	wrong_Feedback("chahada 3ozoba", 25, 160);
		std::cout << wrong_Feedback; // should not be printed because of exception (GradeTooLowException)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
