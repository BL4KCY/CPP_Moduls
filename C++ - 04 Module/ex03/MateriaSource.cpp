#include "MateriaSource.hpp"




MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			inventory[i] = copy.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	// todo: delete all inventory
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& assign)
{
	if (this == &assign)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		// todo: delete all inventory
		if (assign.inventory[i])
			inventory[i] = assign.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	return *this;
}


void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}

