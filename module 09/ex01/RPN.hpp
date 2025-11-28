#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define OPS "+-/*"

class RPN
{
	private:
		std::stack<int>	_stack;
		void	calculate(char& op);
	public:
		~RPN();
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

		void	getInput(std::string arg);
};

#endif
