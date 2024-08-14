#include "Character.hpp"

//____________Character concrete_____________//

Character::Character()
{
	this->name = "default";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& copy)
{
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::~Character()
{
	// todo: delete all inventory
}

Character&	Character::operator=(const Character& assign)
{
	this->name = assign.name;
	for (int i = 0; i < 4; i++)
	{
		if (assign.inventory[i] != NULL)
			this->inventory[i] = assign.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return *this;
}


std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}

