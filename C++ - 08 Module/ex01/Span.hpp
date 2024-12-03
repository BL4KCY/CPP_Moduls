#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>
#include <exception>
#include <limits>
#include <numeric>

class Span
{
private:
	std::vector<int>		intSet;
	unsigned int		maxSize;
public:
	Span();
	Span( unsigned int N );
	Span( const Span& cp );
	Span&	operator = ( Span& cp );
	~Span();
	unsigned int getMaxSize( void ) const;
	std::vector<int>	getIntSet( void ) const;
	void	addNumber( const int _number );
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) >  static_cast<unsigned int>(maxSize - intSet.size())) {
			throw std::overflow_error("Span: Not enough space in Span to add all numbers!");
		}
		intSet.insert(intSet.end(), begin, end);
	}
};

#endif // Span_HPP