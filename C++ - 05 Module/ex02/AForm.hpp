#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public :
		AForm(void);
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		virtual			~AForm(void);
		AForm&			operator=(AForm const &rhs);
		std::string		getName(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		bool			getSigned(void) const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream &out, AForm const &rhs);

#endif