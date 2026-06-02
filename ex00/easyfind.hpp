#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

// Looks for the first occurrence of "value" inside the container "container".
// On success returns an iterator to the found element.
// If nothing is found we throw, the same way at() would complain.
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("value not found in container");
	return it;
}

#endif
