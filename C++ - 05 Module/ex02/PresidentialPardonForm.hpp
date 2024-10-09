#ifndef PPF_HPP
#define PPF_HPP
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		void	execute(Bureaucrat const &executor) const;
};


#endif // PPF_HPP