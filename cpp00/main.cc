#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int	main(void)
{
	string str = "-031362";

	int n;

	stringstream strstrm;
	strstrm << str;
	strstrm >> n;
	cout << n << endl;

}
