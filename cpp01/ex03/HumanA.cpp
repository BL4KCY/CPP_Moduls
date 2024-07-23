#include "HumanA.hpp"



std::string	HumanA::getName(void)
{
	return (this->name);
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}


void	HumanA::attack(void)
{
	std::cout << this->getName()
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}
