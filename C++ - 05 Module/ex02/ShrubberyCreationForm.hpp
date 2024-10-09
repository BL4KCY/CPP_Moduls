#ifndef SCF_HPP
#define SCF_HPP
# include "AForm.hpp"
# include <fstream>



class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		void	execute(Bureaucrat const &executor) const;
};


#endif // SCF_HPP