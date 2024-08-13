#include "WrongAnimal.hpp"

//_____________| WrongAnimal Class Src|_______________//

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destroyed" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void		WrongAnimal::setType(std::string type)
{
	this->type = type;
}

