#include "HumanB.hpp"

std::string	HumanB::getName(void)
{
	return (this->name);
}

void	HumanB::attack(void)
{
	std::cout << this->getName()
	<< " attacks with their "
	<< this->weapon->getType()
	<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}
