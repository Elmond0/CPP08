#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

// A std::stack that we make iterable. std::stack hides its underlying
// container behind the "protected" member c, so by inheriting from it we
// can hand out the iterators of that container.
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

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		// "c" is the protected member of std::stack holding the real container
		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }

		const_iterator begin(void) const { return this->c.begin(); }
		const_iterator end(void) const { return this->c.end(); }

		reverse_iterator rbegin(void) { return this->c.rbegin(); }
		reverse_iterator rend(void) { return this->c.rend(); }

		const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
		const_reverse_iterator rend(void) const { return this->c.rend(); }
};

#endif
