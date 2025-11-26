#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <cstddef>
#include <iterator>

class Span {
public:
	explicit Span(unsigned int N);
	Span();
	~Span();
	Span(const Span& other);
	Span(Span&&) = default;                // add move ctor
	Span& operator=(const Span& other);
	Span& operator=(Span&&) = default;     // add move assign

	void addNumber(int n);
	void addNumber(std::initializer_list<int> il); // convenience

	template<typename InputIt>
	void addRange(InputIt first, InputIt last);   // inline template below

	long long shortestSpan() const;   // bigger signed type
	long long longestSpan()  const;

	void printValues() const;

	std::size_t size() const noexcept { return _vec.size(); }
	std::size_t capacity() const noexcept { return _cap; }

private:
	std::vector<int> _vec;
	std::size_t _cap;
};

// Inline template implementation (no separate .inl needed)
template<typename InputIt>
void Span::addRange(InputIt first, InputIt last)
{
	const std::size_t addCount = static_cast<std::size_t>(std::distance(first, last));
	if (_vec.size() + addCount > _cap)
		throw std::length_error("Span::addRange would exceed capacity");
	_vec.insert(_vec.end(), first, last);
}

inline void Span::addNumber(std::initializer_list<int> il)
{
	addRange(il.begin(), il.end());
}
#endif