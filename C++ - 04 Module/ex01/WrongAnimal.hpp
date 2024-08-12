#pragma once

#include <iostream>
#include <string>

//_____________| WrongAnimal Class|_______________//
class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal&	operator=(const WrongAnimal &copy);
	~WrongAnimal();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
