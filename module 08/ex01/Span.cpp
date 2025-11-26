#include "Span.hpp"

Span::Span(unsigned int N)
	: _vec()
	, _cap(static_cast<std::size_t>(N))
{
	_vec.reserve(_cap);
}

Span::Span()
	: _vec()
	, _cap(0)
{}

Span::~Span() {}

Span::Span(const Span& other)
	: _vec(other._vec)
	, _cap(other._cap)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		_vec = other._vec;
		_cap = other._cap;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_vec.size() >= _cap)
		throw std::length_error("Span::addNumber no space left");
	_vec.push_back(n);
}

long long Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw std::length_error("Span::shortestSpan not enough elements");

	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());

	long long minDist = std::numeric_limits<long long>::max();
	for (std::size_t i = 1; i < tmp.size(); ++i) {
		long long diff = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]);
		if (diff < minDist) minDist = diff;
	}
	return minDist;
}

long long Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw std::length_error("Span::longestSpan not enough elements");
	auto mm = std::minmax_element(_vec.begin(), _vec.end());
	return static_cast<long long>(*mm.second) - static_cast<long long>(*mm.first);
}

void Span::printValues() const
{
	for (std::size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}