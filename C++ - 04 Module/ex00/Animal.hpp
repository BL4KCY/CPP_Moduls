#pragma once

#include <iostream>
#include <string>

//_____________| Animal Class|_______________//
class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &copy);
	Animal&	operator=(const Animal &copy);
	virtual ~Animal();

	virtual void	makeSound() const;
	virtual std::string	getType( void ) const;
	virtual void		setType(std::string type);
};
