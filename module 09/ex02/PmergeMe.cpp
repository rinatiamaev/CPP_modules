#include "PmergeMe.hpp"

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

void PmergeMe::parseInput(char **av)
{
	for (int i = 1; av[i]; ++i)
	{
		int val;
		try { val = std::stoi(av[i]); }
		catch (...) { throw std::runtime_error("argument not integer"); }

		if (val < 0) throw std::runtime_error("argument not positive number");
		if (std::count(_vec.begin(), _vec.end(), val)) throw std::runtime_error("duplicate in argument list");

		_vec.push_back(val);
	}
	_deq = std::deque<int>(_vec.begin(), _vec.end());
}

template <typename Container>
void PmergeMe::insertInContainer(Container &cont, int pair_size)
{
	if (pair_size == 0) return;

	Container main, pend;
	size_t block = pair_size;
	size_t i = block;

	main.insert(main.begin(), cont.begin(), cont.begin() + pair_size);
	for (; i + block <= cont.size(); i += block * 2)
		main.insert(main.end(), cont.begin() + i, cont.begin() + i + block);
	for (i = pair_size * 2; i + block <= cont.size(); i += block * 2)
		pend.insert(pend.end(), cont.begin() + i, cont.begin() + i + block);

	int jacob_idx = INIT_JACOB_NBR;
	int next_jacob, last_jacob = 1;

	std::vector<size_t> idx_vec;
	size_t insert_i;

	for (; !pend.empty(); ++jacob_idx)
	{
		next_jacob = std::round((std::pow(2, jacob_idx + 1) + std::pow(-1, jacob_idx)) / 3);

		for (int elem_idx = next_jacob - last_jacob - 1; elem_idx >= 0; --elem_idx)
		{
			if (elem_idx > static_cast<int>(pend.size()) / pair_size - 1)
				elem_idx = pend.size() / pair_size - 1;

			int pend_idx = elem_idx * pair_size;
			idx_vec.clear();

			for (size_t i = pair_size - 1; i < main.size(); i += pair_size)
				idx_vec.push_back(i);

			int insert_val = pend[pend_idx + pair_size - 1];

			auto it = std::lower_bound(idx_vec.begin(), idx_vec.end(), insert_val,
									[&](size_t idx, int val) { return main[idx] < val; });

			if (it == idx_vec.end())
				insert_i = main.size();
			else
				insert_i = *it - (pair_size - 1);

			main.insert(main.begin() + insert_i, pend.begin() + pend_idx, pend.begin() + pend_idx + pair_size);
			pend.erase(pend.begin() + pend_idx, pend.begin() + pend_idx + pair_size);
		}
		last_jacob = next_jacob;
	}

	std::copy(main.begin(), main.end(), cont.begin());
	std::copy(pend.begin(), pend.end(), cont.begin() + main.size());
}

template <typename Container>
void PmergeMe::sortContainer(Container &cont, int pair_size, std::chrono::microseconds &time)
{
	auto start = std::chrono::steady_clock::now();
	int pairs = cont.size() / pair_size;

	for (int i = 1; i <= pairs; ++i)
	{
		int idx = i * pair_size;
		int &right = cont[idx - 1];
		int &left = cont[idx - (pair_size / 2) - 1];

		if (left > right)
		{
			std::swap_ranges(cont.begin() + idx - (pair_size / 2),
							cont.begin() + idx,
							cont.begin() + idx - pair_size);
		}
	}

	int new_pair_size = pair_size * 2;
	if (cont.size() / new_pair_size > 0)
		sortContainer(cont, new_pair_size, time);

	insertInContainer(cont, pair_size / 2);
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void PmergeMe::sortVector(int pair_size)
{
	sortContainer(_vec, pair_size, _vecTime);
}

void PmergeMe::sortDeq(int pair_size)
{
	sortContainer(_deq, pair_size, _deqTime);
}

template <typename Container>
void PmergeMe::printContainer(const Container &cont, const std::string &name, std::chrono::microseconds time)
{
	for (auto &v : cont) std::cout << v << " ";
	std::cout << "\nTime: " << time.count() << " us\n";
	std::cout << name << ": " << (isSorted(cont.begin(), cont.end()) ? "OK" : "KO") << std::endl;
}

void PmergeMe::printResult(char **av)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; ++i) std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After (vector): ";
	printContainer(_vec, "Vector", _vecTime);

	std::cout << "After (deque): ";
	printContainer(_deq, "Deque", _deqTime);
}