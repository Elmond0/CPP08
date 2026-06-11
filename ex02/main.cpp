#include "MutantStack.hpp"

int main(void)
{
	std::cout << "=== MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
        std::cout << "Last in:	" << mstack.top() << std::endl;
        mstack.pop();
		std::cout << "Size:		" << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << std::endl << *it << std::endl;
		++it;
		std::cout << "++it" << std::endl << *it << std::endl;
		--it;
		std::cout << "--it" << std::endl << *it << std::endl;
		std::cout << std::endl << "Print all stack:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "=== std::list ===" << std::endl;
	{
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << "Last in:	" << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << "Size:		"<< lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();
		std::cout << std::endl << *it << std::endl;
		++it;
		std::cout << "++it" << std::endl << *it << std::endl;
		--it;
		std::cout << "--it" << std::endl << *it << std::endl;
		std::cout << std::endl << "Print all stack:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}
