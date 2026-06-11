#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <deque>
#include <iostream>
#include <list>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void) {}
		MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			std::stack<T, Container>::operator=(other);
			return *this;
		}
		~MutantStack(void) {}

		typedef typename Container::iterator       iterator;

		iterator begin(void) { return this->c.begin(); }
		iterator end(void)   { return this->c.end(); }
};

#endif
