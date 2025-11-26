#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <cstddef>

// "not found" sentinel (no namespace)
constexpr std::size_t EASYFIND_NPOS = static_cast<std::size_t>(-1);

// returns index of first occurrence or EASYFIND_NPOS if not found
template <typename Container>
std::size_t easyfind(const Container& cont, int toFind)
{
	auto first = std::begin(cont);
	auto last  = std::end(cont);
	auto it = std::find(first, last, toFind);
	if (it == last) return EASYFIND_NPOS;
	return static_cast<std::size_t>(std::distance(first, it));
}

#endif
