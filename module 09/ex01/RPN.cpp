#include "RPN.hpp"

void	RPN::calculate(char& op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("operator has no operand");
	int	right = _stack.top();
	_stack.pop();
	int	left = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '*':
		{
			return _stack.push(left * right);
		}
		case '/':
		{
			if (right == 0)
				throw std::runtime_error("division by zero forbidden");
			return _stack.push(left / right);
		}
		case '-':
		{
			return _stack.push(left - right);
		}
		case '+':
		{
			return _stack.push(left + right);
		}
	}
}

void	RPN::getInput(std::string arg)
{
	std::string	ops = OPS;
	bool		check_space = false;

	for (char &c : arg)
	{
		if (!check_space)
		{
			if (std::isdigit(c))
				_stack.push(c - '0');
			else if (ops.find(c) != std::string::npos)
				calculate(c);
			else
				throw std::runtime_error("invalid character");
			check_space = true;
		}
		else
		{
			if (c != ' ')
				throw std::runtime_error("invalid character");
			check_space = false;
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("operand has no operator");
	std::cout << _stack.top() << std::endl;
}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
	: _stack{other._stack}
{}

RPN& RPN::operator =(const RPN& other)
{
	if (this == &other)
		return *this;
	_stack = other._stack;
	return *this;
}

RPN::RPN()
	: _stack{}
{}
