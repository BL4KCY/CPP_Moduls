#pragma once

#include "AMateria.hpp"





//______________IMateriaSource interface_____________//
class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};
