#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap: " << name << " is created (Default name)" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap: " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	this->name = copy.name;
	hitPoint = copy.hitPoint;
	energyPoint = copy.energyPoint;
	attackDamage = copy.attackDamage;

	std::cout << "ScavTrap: " << name << " is copied" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	
	std::cout << "ScavTrap: " << name << " is assigned" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << name << " is destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap: " << name << " attack " << target << " causing " << attackDamage << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << name << " have enterred in Gate keeper mode" << std::endl;
}
