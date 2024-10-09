#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";	
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("RobotomyRequestForm", 72, 45) 
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw std::logic_error(this->getName() + " Form not signed");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
    srand(time(NULL));
    // system("nvlc /nfs/homes/melfersi/Downloads/DrillNoises.mp3 > /dev/null 2>&1 &");
    std::cout << "🤖 Rrrrzzzzzzzz 🤖" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully ✅" << std::endl;
    else
        std::cout << this->_target << " robotomization failed ❌" << std::endl;
}
