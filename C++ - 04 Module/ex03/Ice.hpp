#pragma once

#include "Character.hpp"

//___________Ice Concrete______________//
class	Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	~Ice();
	Ice&	operator=(const Ice& iceObj);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
