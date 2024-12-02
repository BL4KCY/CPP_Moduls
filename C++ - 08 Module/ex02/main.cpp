#include "MutantStack.hpp"
#include <iostream>




int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	std::cout << "more tests" << std::endl;
	MutantStack<int> mstack2;
	mstack2.push(1);
	mstack2.push(2);
	mstack2.push(3);
	mstack2.push(4);
	mstack2.push(5);
	mstack2.push(6);
	mstack2.push(7);

	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "Reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator rit2 = mstack2.rbegin();
	MutantStack<int>::reverse_iterator rite2 = mstack2.rend();
	++rit2;
	--rit2;
	while (rit2 != rite2)
	{
		std::cout << *rit2 << std::endl;
		++rit2;
	}
	return 0;
}