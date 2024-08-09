#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("unamed_clap_name")
{
	this->name = "unamed";
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap: " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap: " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap): ClapTrap(diamondTrap.getName() + "_clap_name"), ScavTrap(diamondTrap.getName()), FragTrap(diamondTrap.getName())
{
	this->name = diamondTrap.name;
	setHitPoint(diamondTrap.getHitPoint());
	setEnergyPoint(diamondTrap.getEnergyPoint());
	setAttackDamage(diamondTrap.getAttackDamage());
	std::cout << "DiamondTrap: " << this->name << " is copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	this->name = diamondTrap.name;
	setHitPoint(diamondTrap.getHitPoint());
	setEnergyPoint(diamondTrap.getEnergyPoint());
	setAttackDamage(diamondTrap.getAttackDamage());
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
	std::cout << "ClapTrap: " << ClapTrap::getName() << std::endl;
}


