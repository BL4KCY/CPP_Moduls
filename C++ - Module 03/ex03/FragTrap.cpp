#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap: " << name << " is created (Default name)" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->name = name;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap: " << name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	this->name = copy.name;
	hitPoint = copy.hitPoint;
	energyPoint = copy.energyPoint;
	attackDamage = copy.attackDamage;

	std::cout << "FragTrap: " << name << " is copied" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;

	std::cout << "FragTrap: " << name << " is assigned" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << name << " is destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap: " << name << " attack " << target << " causing " << attackDamage << " points of damage" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << name << " give me five" << std::endl;
}
