#include "PmergeMe.hpp"
# include <cctype>
# include <functional>
# include <ctype.h>

template <typename T>
void	print_pair(pair<T, T> pr)
{
	cout << "first: " << pr.first << ", second: " << pr.second << endl;
}


int main( int c, char **av ) {
	vector<pair<int, int> >	pairVec;
	pair<int, int>			nbPiar;
	string					arg;
	
	try {
		for (int i = 1; i < c;i++)
		{
			if (string(av[i]).find_first_not_of("0123456789") != string::npos ){ //check if arg is positive number
				throw std::logic_error(av[i] + string(" <- invalid number!!"));
			}
			if (i % 2) {
				nbPiar.first = std::atol(av[i]);
			} else {
				nbPiar.second = std::atol(av[i]);
				if (nbPiar.second < nbPiar.first)
					std::swap(nbPiar.first, nbPiar.second);
				pairVec.push_back(nbPiar);
			}
		}
		if (!(c % 2)){
			pairVec.push_back(pair<int, int>(std::atol(av[c - 1]), -1));
		}
		for_each(pairVec.begin(), pairVec.end(), print_pair<int>);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}