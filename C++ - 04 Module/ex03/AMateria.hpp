#pragma once


#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string	type;
public:
	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria& copy);
	virtual ~AMateria();
	AMateria&	operator=(const AMateria& amateriaObj);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
