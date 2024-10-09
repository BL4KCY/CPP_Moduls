#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int _grade;
	public :
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &rhs);
		int			getGrade(void) const;
		std::string	getName(void) const;
		void 		incrementGrade(void);
		void 		decrementGrade(void);
		void		signForm(Form &form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs);

// Exceptions
class GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too high");
		}
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too low");
		}
};

#endif