#include "PmergeMe.hpp"

void	PmergeMe::printResult(char **av)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; ++i)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (auto &c : _vec)
		std::cout << c << " ";
	std::cout << std::endl;

	std::cout
	<< "Time to process a range of " << (_vec.size()) << " elements with std::vector : " << _vecTime << std::endl;

	std::cout
	<< "Time to process a range of " << (_deq.size()) << " elements with std::deque : " << _deqTime	<< std::endl;

	if (!isSorted(_vec.begin(), _vec.end()))
		std::cout << "Vector: KO" << std::endl;
	else
		std::cout << "Vector: OK" << std::endl;
	if (!isSorted(_deq.begin(), _deq.end()))
		std::cout << "Deque: KO" << std::endl;
	else
		std::cout << "Deque: OK" << std::endl;
}

void	PmergeMe::parseInput(char **av)
{
	int	val;

	for (int i = 1; av[i]; ++i)
	{
		try
		{
			val = std::stoi(av[i]);
		}
		catch (std::exception &e)
		{
			throw std::runtime_error("argument not integer");
		}

		if (val < 0)
			throw std::runtime_error("argument not positive number");
		if (std::find(_vec.begin(), _vec.end(), val) != _vec.end())
			throw std::runtime_error("duplicate in argument list");
		_vec.push_back(val);
		_deq.push_back(val);
	}
}

void	PmergeMe::insertInDeq(int pair_size)
{
	if (pair_size == 0)
		return ;

	std::deque<int>	main;
	std::deque<int>	pend;

	size_t	block = pair_size;
	size_t	i = block;

	main.insert(main.begin(), _deq.begin(), _deq.begin() + pair_size);
	for (; i + block <= _deq.size(); i += block * 2)
		main.insert(main.end(), _deq.begin() + i, _deq.begin() + i + block);
	for (i = pair_size * 2; i + block <= _deq.size(); i += block * 2)
		pend.insert(pend.end(), _deq.begin() + i, _deq.begin() + i + block);

	int	jacob_nbr_idx = INIT_JACOB_NBR;
	int	next_jacob_nbr;
	int	last_jacob_nbr = 1;

	std::deque<size_t>	idx_vec;
	size_t insert_i;
	for (; !pend.empty(); ++jacob_nbr_idx)
	{
		next_jacob_nbr = std::round((std::pow(2, jacob_nbr_idx + 1) + std::pow(-1, jacob_nbr_idx)) / 3);
		for (int elem_idx = next_jacob_nbr - last_jacob_nbr - 1; elem_idx >= 0; --elem_idx)
		{
			if (elem_idx > static_cast<int>(pend.size()) / pair_size - 1)
				elem_idx = pend.size() / pair_size - 1;

			int pend_idx = elem_idx * pair_size;
			idx_vec.clear();

			for (size_t i = pair_size - 1; i < main.size(); i += pair_size)
				idx_vec.push_back(i);

			int insert_val = pend[pend_idx + pair_size - 1];

			auto it = std::lower_bound(
				idx_vec.begin(), idx_vec.end(),
				insert_val,
				[&](size_t idx, int val){ return *(main.begin() + idx) < val;}
			);

			if (it == idx_vec.end())
				insert_i = main.size();
			else
				insert_i = *it - (pair_size - 1);

			main.insert(
				main.begin() + insert_i,
				pend.begin() + pend_idx,
				pend.begin() + pend_idx + pair_size
			);

			pend.erase(
				pend.begin() + pend_idx,
				pend.begin() + pend_idx + pair_size
			);
		}
		last_jacob_nbr = next_jacob_nbr;
	}

	std::copy(main.begin(), main.end(), _deq.begin());
	std::copy(pend.begin(), pend.end(), _deq.begin() + main.size());
}

void	PmergeMe::sortDeq(int pair_size)
{
	auto	start = std::chrono::steady_clock::now();
	int pairs = _deq.size() / pair_size;

	for (int i = 1; i < pairs + 1; ++i)
	{
		int deq_idx = i * pair_size;
		int right = *(_deq.begin() + deq_idx - 1);
		int& left = *(_deq.begin() + deq_idx - (pair_size / 2) - 1);

		if (left > right)
		{
			std::swap_ranges(
				_deq.begin() + deq_idx - (pair_size / 2),
				_deq.begin() + deq_idx,
				_deq.begin() + deq_idx - pair_size
			);
		}
	}
	int new_pair_size = pair_size * 2;
	if (_deq.size() / new_pair_size > 0)
		sortDeq(new_pair_size);
	insertInDeq(pair_size / 2);

	auto	end = std::chrono::steady_clock::now();
	_deqTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void	PmergeMe::insertInVec(int pair_size)
{
	if (pair_size == 0)
		return ;

	std::vector<int>	main;
	std::vector<int>	pend;

	size_t	block = pair_size;
	size_t	i = block;

	main.insert(main.begin(), _vec.begin(), _vec.begin() + pair_size);
	for (; i + block <= _vec.size(); i += block * 2)
		main.insert(main.end(), _vec.begin() + i, _vec.begin() + i + block);
	for (i = pair_size * 2; i + block <= _vec.size(); i += block * 2)
		pend.insert(pend.end(), _vec.begin() + i, _vec.begin() + i + block);

	int	jacob_nbr_idx = INIT_JACOB_NBR;
	int	next_jacob_nbr;
	int	last_jacob_nbr = 1;

	std::vector<size_t>	idx_vec;
	size_t insert_i;
	for (; !pend.empty(); ++jacob_nbr_idx)
	{
		next_jacob_nbr = std::round((std::pow(2, jacob_nbr_idx + 1) + std::pow(-1, jacob_nbr_idx)) / 3);
		for (int elem_idx = next_jacob_nbr - last_jacob_nbr - 1; elem_idx >= 0; --elem_idx)
		{
			if (elem_idx > static_cast<int>(pend.size()) / pair_size - 1)
				elem_idx = pend.size() / pair_size - 1;

			int pend_idx = elem_idx * pair_size;
			idx_vec.clear();

			for (size_t i = pair_size - 1; i < main.size(); i += pair_size)
				idx_vec.push_back(i);

			int insert_val = pend[pend_idx + pair_size - 1];

			auto it = std::lower_bound(
				idx_vec.begin(), idx_vec.end(),
				insert_val,
				[&](size_t idx, int val){ return main[idx] < val;}
			);

			if (it == idx_vec.end())
				insert_i = main.size();
			else
				insert_i = *it - (pair_size - 1);

			main.insert(
				main.begin() + insert_i,
				pend.begin() + pend_idx,
				pend.begin() + pend_idx + pair_size
			);

			pend.erase(
				pend.begin() + pend_idx,
				pend.begin() + pend_idx + pair_size
			);
		}
		last_jacob_nbr = next_jacob_nbr;
	}

	std::copy(main.begin(), main.end(), _vec.begin());
	std::copy(pend.begin(), pend.end(), _vec.begin() + main.size());
}

void	PmergeMe::sortVector(int pair_size)
{
	auto	start = std::chrono::steady_clock::now();
	int pairs = _vec.size() / pair_size;

	for (int i = 1; i < pairs + 1; ++i)
	{
		int vec_idx = i * pair_size;
		int& right = _vec[vec_idx - 1];
		int& left = _vec[vec_idx - (pair_size / 2) - 1];

		if (left > right)
		{
			std::swap_ranges(
				_vec.begin() + vec_idx - (pair_size / 2),
				_vec.begin() + vec_idx,
				_vec.begin() + vec_idx - pair_size
			);
		}
	}
	int new_pair_size = pair_size * 2;
	if (_vec.size() / new_pair_size > 0)
		sortVector(new_pair_size);
	insertInVec(pair_size / 2);

	auto	end = std::chrono::steady_clock::now();
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
};

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	_vec = other._vec;
	_vecTime = other._vecTime;
	_deq = other._deq;
	_deqTime = other._deqTime;
	return *this;
}
