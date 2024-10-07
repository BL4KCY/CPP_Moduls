#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public :
		Form(void);
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		~Form(void);
		Form&		operator=(Form const &rhs);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
};

std::ostream&	operator<<(std::ostream &out, Form const &rhs);

#endif