#include "HumanB.hpp"



std::string	HumanB::getName(void)
{
	return (this->name);
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

void	HumanB::attack(void)
{
	std::cout << this->getName()
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = weapon;
}
