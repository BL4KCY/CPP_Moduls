#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ClapTrap("unamed_clap_name"), ScavTrap("unamed"), FragTrap("unamed")
{
	this->name = "unamed";
	std::cout << "DiamondTrap " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	std::cout << "DiamondTrap " << this->name << " is created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " is destroyed" << std::endl;
}
