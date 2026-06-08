#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(void){}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is already full");
	_numbers.push_back(number);
}

int Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i + 1 < sorted.size(); ++i)
	{
		int gap = sorted[i + 1] - sorted[i];
		if (gap < shortest)
			shortest = gap;
	}
	return shortest;
}

int Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return max - min;
}
