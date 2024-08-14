#pragma once

#include "IMateriaSource.hpp"


class MateriaSource: public IMateriaSource
{
private:
	AMateria*	inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& assign);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};
