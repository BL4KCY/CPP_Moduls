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

template <typename T>
int	easyfind(T container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return  *it;
	throw std::runtime_error("Not found!!");
}

#endif // WHATEVER_HPP