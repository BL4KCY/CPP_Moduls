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


//	Copies the Materia passed as a parameter and store it in memory so it can be cloned
//	later. Like the Character, the MateriaSource can know at most 4 Materias. They
//	are not necessarily unique.
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

//	Searches for a Materia in the inventory that matches the type passed as a parameter.
//	If it finds it, it clones it and returns it. If it doesn't find it, it returns NULL.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && (inventory[i]->getType() == type))
			return inventory[i]->clone();
	}
	return NULL;
}

