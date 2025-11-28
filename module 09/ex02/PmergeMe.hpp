#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <chrono>

#define INIT_PAIR_SIZE 2
#define INIT_JACOB_NBR 2

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::chrono::microseconds	_vecTime;
		std::chrono::microseconds	_deqTime;

		void	insertInVec(int pair_size);
		void	insertInDeq(int pair_size);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void	parseInput(char **av);
		void	sortVector(int pair_size);
		void	sortDeq(int pair_size);
		void	printResult(char **av);

	template <typename It>
	bool	isSorted(It begin, It end)
	{
		for (auto last = *begin; begin != end; ++begin)
		{
			if (last > *begin)
				return false;
			last = *begin;
		}
		return true;
	}
};

#endif
