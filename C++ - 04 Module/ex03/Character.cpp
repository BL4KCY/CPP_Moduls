#include "Character.hpp"

//____________Character concrete_____________//

Character::Character()
{
	this->name = "default";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->inventoryCopy[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->inventoryCopy[i] = NULL;
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
	for (int i = 0; i < 4; i++)
		this->inventoryCopy[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	this->addToInventoryCopy(NULL);
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
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->addToInventoryCopy(NULL);
			if (inInventory(m))
				this->inventory[i] = m->clone();
			else
				this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->inventory[idx] != NULL)
		{
			this->addToInventoryCopy(this->inventory[idx]);
			this->inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}


bool	Character::inInventory(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == m)
			return true;
	}
	return false;
}

void	Character::addToInventoryCopy(AMateria* m)
{
	if (m == NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventoryCopy[i] != NULL)
				delete this->inventoryCopy[i];
			this->inventoryCopy[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventoryCopy[i] == NULL)
		{
			this->inventoryCopy[i] = m;
			break;
		}
	}
}
