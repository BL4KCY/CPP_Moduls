#include "ClapTrap.hpp"




ClapTrap::ClapTrap(): name("unamed"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap: " << this->name << " is created (Default name)" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap: " << this->name << " is created" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	std::cout << "ClapTrap: " << this->name << " is copied" << std::endl;
}
ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	std::cout << "ClapTrap: " << this->name << " assigned" << std::endl;
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->name << " is destroyed" << std::endl;
}
void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoint && this->energyPoint)
	{
		std::cout << "ClapTrap: " << this->name
		<< " attack " << target << ", causing "
		<< this->attackDamage << " points of damage!"
		<< std::endl;
		this->energyPoint--;
	}
	if (!this->hitPoint)
		std::cout << this->name << " is dead" << std::endl;
	if (!this->energyPoint)
		std::cout << this->name << " has no energy point" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= amount;
	if (this->hitPoint < 0)
		this->hitPoint = 0;
	std::cout << this->name << " is damaged by " << amount << " points" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint && this->hitPoint)
	{
		this->energyPoint--;
		this->hitPoint += amount;
		std::cout << this->name << " is repaired by " << amount << " points" << std::endl;
	}
	else if (!this->hitPoint)
	{
		std::cout << this->name << " is dead" << std::endl;
	}
	else
	{
		std::cout << this->name << " has no energy point" << std::endl;
	}
}
