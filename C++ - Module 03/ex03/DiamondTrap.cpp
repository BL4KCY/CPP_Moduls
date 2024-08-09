#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("unamed_clap_name")
{
	name = "unamed";
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap: " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap: " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap): ClapTrap(name + "_clap_name")
{
	this->name = diamondTrap.name;
	std::cout << "DiamondTrap: " << this->name << " is copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	this->name = diamondTrap.name;
	this->hitPoint = diamondTrap.hitPoint;
	this->energyPoint = diamondTrap.energyPoint;
	this->attackDamage = diamondTrap.attackDamage;
	std::cout << "DiamondTrap: " << this->name << " is assigned" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << this->name << " is destroyed" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << this->name << std::endl;
	std::cout << "ClapTrap: " << ClapTrap::name << std::endl;
}


