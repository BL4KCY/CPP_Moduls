#include "Animal.hpp"

//_____________| Animal Class Src|_______________//

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal Created" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "Animal copied" << std::endl;
}

Animal&	Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destroyed" << std::endl;
}

void	Animal::makeSound() const {}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void		Animal::setType(std::string type)
{
	this->type = type;
}

