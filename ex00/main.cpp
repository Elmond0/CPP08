#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2); // 0 2 4 6 8 ...

	// found case
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 8);
		std::cout << "found " << *it << " at index "
				  << (it - vec.begin()) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	// not found case
	try
	{
		easyfind(vec, 7);
		std::cout << "this line should never print" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	// works on a list too
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(21);
	lst.push_back(84);
	try
	{
		std::list<int>::iterator it = easyfind(lst, 21);
		std::cout << "found " << *it << " in the list" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
