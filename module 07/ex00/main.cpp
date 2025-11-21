#include <iostream>
#include <string>
#include "swap.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}

// class Awesome {
// public:
//     Awesome() : _n(0) {}
//     Awesome(int n) : _n(n) {}
//     Awesome(const Awesome & a) : _n(a._n) {} // copy constructor

//     Awesome & operator=(const Awesome & a) { _n = a._n; return *this; } // const reference
//     // Optionally a move assignment (C++11)
//     Awesome & operator=(Awesome && a) noexcept { _n = a._n; return *this; }

//     bool operator==(const Awesome & rhs) const { return _n == rhs._n; }
//     bool operator!=(const Awesome & rhs) const { return _n != rhs._n; }
//     bool operator>(const Awesome & rhs) const { return _n > rhs._n; }
//     bool operator<(const Awesome & rhs) const { return _n < rhs._n; }
//     bool operator>=(const Awesome & rhs) const { return _n >= rhs._n; }
//     bool operator<=(const Awesome & rhs) const { return _n <= rhs._n; }

//     int get_n() const { return _n; }
// private:
//     int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
// int main(void)
// {
// Awesome a(2), b(4);
// swap(a, b);
// std::cout << a << " " << b << std::endl;
// std::cout << max(a, b) << std::endl;
// std::cout << min(a, b) << std::endl;
// return (0);
// }
