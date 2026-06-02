#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

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

		// fill the Span from a range of iterators in one call
		template <typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			for (InputIterator it = begin; it != end; ++it)
			{
				if (_numbers.size() >= _maxSize)
					throw std::out_of_range("Span is full");
				_numbers.push_back(*it);
			}
		}

		// exceptions
		class FullSpanException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#endif
