#ifndef RRF_HPP
#define RRF_HPP
# include "AForm.hpp"
# include <stdlib.h>



class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		void	execute(Bureaucrat const &executor) const;
};


#endif // RRF_HPP