#include "Span.hpp"



Span::Span() : maxSize(5)
{

}

Span::Span(unsigned int N) : maxSize(N)
{

}

Span::Span(const Span& cp): maxSize(cp.getMaxSize())
{
	this->intSet = cp.getIntSet();
}

Span&	Span::operator = (Span& cp)
{
	this->intSet = cp.getIntSet();
	this->maxSize = cp.getMaxSize();
	return *this;
}	

Span::~Span()
{

}

std::set<int>	Span::getIntSet( void ) const
{
	return (intSet);
}

unsigned int	Span::getMaxSize( void ) const
{
	return (maxSize);
}

void	Span::addNumber(const int _number)
{
	if (intSet.size() == maxSize) {
		throw std::overflow_error("Span: No space left to add this number !!");
	}
	intSet.insert(_number);
}

unsigned int	Span::shortestSpan( void ) const
{
	if (intSet.size() < 2){
		throw std::logic_error("Span: need 2 numbers or above !!");
	}
	unsigned int  shortest = std::numeric_limits<unsigned int>::max();
	std::set<int>::iterator current = intSet.begin();
	std::set<int>::iterator next = current;
	for (next++; next != intSet.end(); next++) {
		shortest = std::min(shortest, static_cast<unsigned int>(*next - *current));
		current++;
	}
	return (shortest);
}

unsigned int	Span::longestSpan( void ) const
{
	if (intSet.size() < 2){
		throw std::logic_error("Span: need 2 numbers or above !!");
	}
	return (
		*std::max_element(intSet.begin(), intSet.end())
		-
		*std::min_element(intSet.begin(), intSet.end())
	);
}