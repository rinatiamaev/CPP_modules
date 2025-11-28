#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return 0;

	try
	{
		PmergeMe	exec;
		exec.parseInput(av);
		exec.sortVector(INIT_PAIR_SIZE);
		exec.sortDeq(INIT_PAIR_SIZE);
		exec.printResult(av);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
