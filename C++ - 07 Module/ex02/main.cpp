#include "Array.hpp"

template <typename T>
void	printArray(Array<T> array)
{
	for (uint32_t i = 0; i < array.size(); i++)
		cout << "array[" << i << "]: " <<  array[i] << endl;
}



int main( void )
{
	try
	{
		Array<string> stringArray(10);
		Array<int> intArray(5);

		stringArray[0] = "one";
		stringArray[9] = "ten";

		Array<string> stringArray2;// = stringArray;
		stringArray2 = stringArray;
		// printArray<string>(stringArray);
		printArray<string>(stringArray2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return 0;
}
