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
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap&	operator=(const ClapTrap& copy);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	setHitPoint(int hitPoint);
	int		getHitPoint(void) const;
	void	setEnergyPoint(int energyPoint);
	int		getEnergyPoint(void) const;
	void	setAttackDamage(int attackDamage);
	int		getAttackDamage(void) const;
	std::string	getName(void) const;
	void	setName(std::string name);
};
