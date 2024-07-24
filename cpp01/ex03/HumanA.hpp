

#pragma once

#include "Weapon.hpp"


class HumanA
{
private:
	std::string	name;
	Weapon&		weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	void		attack(void);
	std::string	getName(void);
	void		setName(std::string name);
	void		setWeapon(Weapon weapon);
};
