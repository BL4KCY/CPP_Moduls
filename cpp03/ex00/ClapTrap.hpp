#pragma once

#include <iostream>
#include <string>




class ClapTrap
{
private:
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap&	operator=(const ClapTrap& copy);
	~ClapTrap();
	//-----------attributes----------------//
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
