#include "Array.hpp"

template <class T>
void	printArray(Array<T> array)
{
	for (uint32_t i = 0; i < array.size(); i++)
		cout << "array[" << i << "]: " <<  array[i] << endl;
}

template <typename T>
void	fillArray(Array<T> &array, T value)
{
	for (uint32_t i = 0; i < array.size(); i++)
		array[i] = value;
}

int main( void )
{
	try
	{
		// default constructor
		Array<int> empty;
		cout << empty.size() << endl;
		// cout << empty[0] << endl; // should throw exception "comment it to check other tests"

		// param constructor
		Array<int> intArray(23);
		cout << intArray.size() << endl;
		intArray[0] = 42;
		cout << intArray[0] << endl;
		// cout << intArray[23] << endl; // should throw exception "comment it to check other tests"

		// copy constructor
		Array<int> copy(intArray);
		cout << copy.size() << endl;
		cout << copy[0] << endl;

		// assignment operator
		Array<int> assign;
		assign = intArray;
		cout << assign.size() << endl;
		cout << assign[0] << endl;
	
		fillArray(intArray, 42);
		fillArray(copy, 13);
		fillArray(assign, 1446);
		// printArray
		cout << "**printArray**" << endl;
		printArray(intArray);
		cout << "**printArray copy**" << endl;
		printArray(copy);
		cout << "**printArray assign**" << endl;
		printArray(assign);
		assign = copy;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return 0;
}
