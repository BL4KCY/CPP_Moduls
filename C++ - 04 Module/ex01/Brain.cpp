#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is created" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain&	Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}

std::string	Brain::getIdea( int index ) const
{
	if (0 <= index && index < 100)
		return (ideas[index]);
	std::cout << "index out of 0-99 (100 idea)" << std::endl;
	return (ideas[0]);
}

void		Brain::setIdea( int index, std::string idea )
{
	if (0 <= index && index < 100)
		ideas[index] = idea;
	std::cout << "index out of 0-99 (100 idea)" << std::endl;
}

