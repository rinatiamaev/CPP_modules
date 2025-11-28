#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./BitcoinExchange <database_name>" << std::endl;
		return 0;
	}
	try
	{
		BitcoinExchange	exec;

		exec.exchange(av[1]);
	}
	catch(std::exception& e)
	{
		std::cout << "Fatal Error: " << e.what() << std::endl;
	}

	return 0;
}
