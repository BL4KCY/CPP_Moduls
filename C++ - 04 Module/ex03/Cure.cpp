#include "Cure.hpp"

Cure::Cure(): AMateria("Cure") {}

Cure::Cure(const Cure& copy): AMateria(copy) {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& CureObj)
{
	AMateria::operator=(CureObj);
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
