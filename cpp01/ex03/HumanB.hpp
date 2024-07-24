

#pragma once

#include "Weapon.hpp"


class HumanB
{
private:
	std::string	name;
	Weapon*		weapon;
public:
	HumanB(std::string name);
	void		attack(void);
	std::string	getName(void);
	void		setWeapon(Weapon& weapon);
	void		setName(std::string name);
};
