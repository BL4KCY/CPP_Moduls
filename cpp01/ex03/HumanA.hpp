

#pragma once

#include "Weapon.hpp"


class HumanA
{
private:
	std::string	name;
	Weapon		weapon;
public:
	void		attack(void);
	std::string	getName(void);
	void		setName(std::string name);
};
