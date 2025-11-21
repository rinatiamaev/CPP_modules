#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
    x++;
}

// int main() {
// 	int intArray[5] = {1, 2, 3, 4, 5};

// 	std::cout << "Print integers:" << std::endl;
// 	iter(intArray, 5, printElement<int>);

// 	std::cout << "Increment integers:" << std::endl;
// 	iter(intArray, 5, increment<int>);
// 	iter(intArray, 5, printElement<int>);

// 	std::string strArray[3] = {"Hello", "World", "!"};

// 	std::cout << "\nPrint strings:" << std::endl;
// 	iter(strArray, 3, printElement<std::string>);


// 	char charArray[4] = {'A', 'B', 'C', 'D'};

// 	std::cout << "\nPrint chars:" << std::endl;
// 	iter(charArray, 4, printElement<char>);

// 	return 0;
// }

class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];
iter( tab, 5, print );
iter( tab2, 5, print );
return 0;
}
