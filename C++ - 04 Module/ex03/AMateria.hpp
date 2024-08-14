#pragma once


#include <iostream>
#include <string>
#include "Character.hpp"


class ICharacter;

class AMateria
{
protected:
	std::string	type;
public:
	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria& copy);
	~AMateria();
	AMateria&	operator=(const AMateria& amateriaObj);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
