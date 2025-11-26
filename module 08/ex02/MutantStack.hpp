#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		~MutantStack();
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);

		typedef typename std::deque<T>::iterator iterator;
		iterator			begin();
		iterator			end();
};

#include "MutantStack.tpp"

#endif
