#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str)
{
	// Check for quoted char
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	
	// Check for single char
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
	
	return false;
}

bool ScalarConverter::isInt(const std::string& str)
{
	if (str.empty()) return false;
	
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length()) return false;
	
	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
	
	std::string number = str.substr(0, str.length() - 1);
	if (number.empty()) return false;
	
	size_t start = 0;
	if (number[0] == '+' || number[0] == '-')
		start = 1;
	
	if (start >= number.length()) return false;
	
	bool hasDot = false;
	for (size_t i = start; i < number.length(); i++)
	{
		if (number[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!std::isdigit(number[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str.empty()) return false;
	
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length()) return false;
	
	bool hasDot = false;
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
	return (str == "nan" || str == "+inf" || str == "-inf" ||
			str == "nanf" || str == "+inff" || str == "-inff");
}

bool ScalarConverter::isDisplayable(int c)
{
	return (c >= 32 && c <= 126);
}

void ScalarConverter::convertFromChar(char c)
{
	if (!isDisplayable(static_cast<int>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
	if (value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	std::cout << "int: " << value << std::endl;
	
	std::cout << "float: " << static_cast<float>(value);
	if (static_cast<float>(value) == static_cast<int>(static_cast<float>(value)) && 
		static_cast<float>(value) >= -1000000 && static_cast<float>(value) <= 1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(value);
	if (static_cast<double>(value) == static_cast<int>(static_cast<double>(value)) && 
		static_cast<double>(value) >= -1000000 && static_cast<double>(value) <= 1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
	if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	if (std::isnan(value) || std::isinf(value) || 
		value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
			std::cout << "float: " << static_cast<int>(value) << ".0f" << std::endl;
		else
			std::cout << "float: " << value << "f" << std::endl;
	}
	
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
			std::cout << "double: " << static_cast<int>(value) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
}

void ScalarConverter::convertFromDouble(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (std::isnan(value) || std::isinf(value) || 
		value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else if (value < -FLT_MAX || value > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
			std::cout << "float: " << static_cast<int>(value) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
	
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
			std::cout << "double: " << static_cast<int>(value) << ".0" << std::endl;
		else
			std::cout << "double: " << value << std::endl;
	}
}

void ScalarConverter::handlePseudoLiteral(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (str == "nanf" || str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return;
	}
	
	if (isPseudoLiteral(str))
	{
		handlePseudoLiteral(str);
		return;
	}
	
	if (isChar(str))
	{
		char c;
		if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
			c = str[1];
		else
			c = str[0];
		convertFromChar(c);
		return;
	}
	
	if (isInt(str))
	{
		std::istringstream iss(str);
		long temp;
		if (iss >> temp && iss.eof())
		{
			if (temp < INT_MIN || temp > INT_MAX)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			int value = static_cast<int>(temp);
			convertFromInt(value);
			return;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	
	if (isFloat(str))
	{
		std::string floatStr = str.substr(0, str.length() - 1); // Remove 'f'
		std::istringstream iss(floatStr);
		float value;
		if (iss >> value && iss.eof())
		{
			convertFromFloat(value);
			return;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	
	if (isDouble(str))
	{
		std::istringstream iss(str);
		double value;
		if (iss >> value && iss.eof())
		{
			convertFromDouble(value);
			return;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	
	std::cout << "Error: Invalid input format" << std::endl;
}
