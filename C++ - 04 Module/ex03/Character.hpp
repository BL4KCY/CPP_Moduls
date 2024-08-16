#pragma once

#include "ICharacter.hpp"

//____________Character concrete_____________//
class Character: public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
	AMateria*	inventoryCopy[4];
	void addToInventoryCopy(AMateria* m);
public:
	Character();
	Character(std::string name);
	Character(const Character& copy);
	~Character();
	Character&	operator=(const Character& assign);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	bool inInventory(AMateria* m);
};
