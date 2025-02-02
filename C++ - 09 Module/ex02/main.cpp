#include "PmergeMe.hpp"
#include "mergeInsertSort.hpp"

int main( int c, char **av ) {
	vector<int>	vec;
	deque<int>	deq;
	
	try {
		for (int i = 1; i < c;i++)
		{
			if (string(av[i]).find_first_not_of("0123456789") != string::npos ){ //check if arg is positive number
				throw std::logic_error(av[i] + string(" <- invalid number!!"));
			}
			vec.push_back(std::atol(av[i]));
			deq.push_back(std::atol(av[i]));
		}
		cout << "before: ";
		for_each(vec.begin(), vec.end(), putnbr);
		cout << endl;
		mergeInsertSort<vector<int> > sortVec(vec);
		mergeInsertSort<deque<int> > sortDeq(deq);
		cout << "after :";
		for_each(sortVec.getarr().begin(), sortVec.getarr().end(), putnbr);
		cout << endl;
		cout << std::fixed << std::setprecision(5);
		cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> : " << sortVec.timeTakes() << " seconds" << endl;
		cout << "Time to process a range of " << deq.size() << " elements with std::deque<int> : " << sortDeq.timeTakes() << " seconds" << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}