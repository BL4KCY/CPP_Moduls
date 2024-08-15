#include "ICharacter.hpp"



AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(){} // i think this ganna be virtual defualt constructor i guess !

AMateria::AMateria(const AMateria& copy)
{
	this->type = copy.type;
}

AMateria::~AMateria() {} // blanc because i don't need it for now !

AMateria&	AMateria::operator=(const AMateria& amateriaObj)
{
	if (this->type != amateriaObj.type)
		this->type = amateriaObj.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
