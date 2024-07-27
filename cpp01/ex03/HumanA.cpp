#include "HumanA.hpp"

std::string	HumanA::getName(void)
{
	return (this->name);
}

void	HumanA::attack(void)
{
	std::cout << this->getName()
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}
