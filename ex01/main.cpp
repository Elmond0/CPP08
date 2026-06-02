#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	// the example from the subject
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	// adding too many numbers should throw
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try
		{
			sp.addNumber(3);
		}
		catch (const std::exception& e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}

	// asking for a span with not enough numbers
	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}

	std::cout << "----------------------" << std::endl;

	// filling with a range of iterators
	{
		std::vector<int> source;
		source.push_back(5);
		source.push_back(8);
		source.push_back(1);
		source.push_back(20);

		Span sp(source.size());
		sp.addRange(source.begin(), source.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	// stress test with a lot of numbers
	{
		const unsigned int N = 10000;
		Span sp(N);

		std::srand(std::time(NULL));
		std::vector<int> big;
		big.reserve(N);
		for (unsigned int i = 0; i < N; ++i)
			big.push_back(std::rand());
		sp.addRange(big.begin(), big.end());

		std::cout << "filled " << N << " numbers" << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	return 0;
}
