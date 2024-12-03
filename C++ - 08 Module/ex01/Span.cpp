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

std::vector<int>	Span::getIntSet( void ) const
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
	intSet.push_back(_number);
}

unsigned int	Span::shortestSpan( void ) const
{
	if (intSet.size() < 2){
		throw std::logic_error("Span: need 2 numbers or above !!");
	}
	std::vector<unsigned int>	diff(intSet.size() - 1);
	std::vector<int>			sorted_list(intSet);
	std::sort(sorted_list.begin(), sorted_list.end());
	std::adjacent_difference(sorted_list.begin(), sorted_list.end(), diff.begin());
	return (*std::min_element(diff.begin() , diff.end()));
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