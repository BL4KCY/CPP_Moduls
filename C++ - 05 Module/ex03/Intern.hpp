#ifndef INTERN_HPP
# define INTERN_HPP
# include <stdint.h>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	private:
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern	&operator=(Intern const &rhs);
		static	AForm*	makeForm(std::string const name, std::string const target);
};


#endif // INTERN_HPP