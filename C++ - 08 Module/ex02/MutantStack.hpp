#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <deque>
#include <stack>

template <typename T, typename _Sequence = std::deque<T> >
class MutantStack : public std::stack<T, _Sequence>
{
public:
	typedef typename _Sequence::iterator iterator;
	typedef typename _Sequence::reverse_iterator reverse_iterator;
	// read and write access iterators
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	// reverse read and write access iterators
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}
};

#endif // MUTANTSTACK_HPP