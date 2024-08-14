#pragma once

#include "Character.hpp"

//___________Cure Concrete______________//
class	Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	~Cure();
	Cure&	operator=(const Cure& CureObj);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
