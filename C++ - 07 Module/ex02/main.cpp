#include "Array.hpp"


int main( void )
{
	try
	{
		unsigned int	n = (int)-1;
		Array<long> a(n);
		for (unsigned long i = 0; i < n  +1;i++)
			cout << a[i] << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return 0;
}
