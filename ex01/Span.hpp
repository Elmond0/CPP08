#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void	addNumber(int number);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		template <typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			for (InputIterator it = begin; it != end; ++it)
			{
				if (_numbers.size() >= _maxSize)
					throw std::runtime_error("Span is already full");
				_numbers.push_back(*it);
			}
		}
};

#endif
