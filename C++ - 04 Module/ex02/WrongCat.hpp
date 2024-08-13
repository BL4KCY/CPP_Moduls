#pragma once

#include "WrongAnimal.hpp"

//_____________| WrongCat Class|_______________//
class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat&	operator=(const WrongCat &copy);
	~WrongCat();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
