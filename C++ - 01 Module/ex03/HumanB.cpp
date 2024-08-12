#include "HumanB.hpp"

std::string	HumanB::getName(void)
{
	return (this->name);
}

void	HumanB::attack(void)
{
	std::cout << this->getName()
	<< " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	else
		std::cout << "no weapon";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}
