#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	this->type = copy.type;
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong: Meow Meow 😺" << std::endl;
}

std::string	WrongCat::getType( void ) const
{
	return (this->type);
}

void		WrongCat::setType(std::string type)
{
	this->type = type;
}
