#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "GradeException.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int _grade;
	public :
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat &operator = (Bureaucrat const &rhs);
		int getGrade(void) const;
		std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif