#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <string>

#define INIT_PAIR_SIZE 2
#define INIT_JACOB_NBR 2

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	std::chrono::microseconds _vecTime;
	std::chrono::microseconds _deqTime;

	template <typename Container>
	void insertInContainer(Container &cont, int pair_size);

	template <typename Container>
	void sortContainer(Container &cont, int pair_size, std::chrono::microseconds &time);

	template <typename Container>
	void printContainer(const Container &cont, const std::string &name, std::chrono::microseconds time);

public:
	PmergeMe() {};
	~PmergeMe() {};
	PmergeMe(const PmergeMe &other) { *this = other; }
	PmergeMe& operator=(const PmergeMe &other);

	void parseInput(char **av);
	void sortVector(int pair_size = INIT_PAIR_SIZE);
	void sortDeq(int pair_size = INIT_PAIR_SIZE);
	void printResult(char **av);

	template <typename It>
	bool isSorted(It begin, It end)
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
