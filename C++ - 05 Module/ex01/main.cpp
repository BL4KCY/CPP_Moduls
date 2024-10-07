#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form	war9a("chahada l7ayat", 10, 20);
		std::cout << war9a;
		try
		{
			std::cout << "-----------| test hassan |--------------" << std::endl;
			Bureaucrat hassan("hassan", 1);
			std::cout << hassan;
			hassan.signForm(war9a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "-----------| test benMossa |--------------" << std::endl;
			Bureaucrat benMoussa("benMossa", 150);
			std::cout << benMoussa;
			benMoussa.signForm(war9a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Form	wrong_war9a("chahada ضهادة", 25, 160);
		std::cout << wrong_war9a; // should not be printed because of exception (GradeTooLowException)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
