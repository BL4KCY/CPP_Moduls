#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>

typedef	unsigned int	index;
typedef	int				integer ;

template <typename T>
int	easyfind(T container, integer value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return  *it;
	throw std::runtime_error("Not found!!");
}

#endif // WHATEVER_HPP