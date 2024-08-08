#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	setHitPoint(copy.getHitPoint());
	setEnergyPoint(copy.getEnergyPoint());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "ScavTrap assinged" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << getName() << " attack " << target << " causing " << this->getAttackDamage() << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}
