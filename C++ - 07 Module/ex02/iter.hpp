#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <string>
#include <iomanip>


using std::cout;
using std::string;
using std::cin;
using std::endl;

template <typename T>
void iter(T *array, int length, void (*f)(T const &))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

#endif // ITER_HPP