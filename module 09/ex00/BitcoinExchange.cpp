#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _priceDb{}
{
	loadDataBase(_priceDb, PATH_PRICE_DB);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _priceDb{other._priceDb}
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	_priceDb = other._priceDb;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

Ymd BitcoinExchange::convertStrToDate(const std::string& date)
{
	static const std::string	fmt = STD_DATE_FORMAT;
	std::tm tm{};
	std::istringstream ss(date);

	if (fmt.length() != date.length())
		throw std::runtime_error("bad date");
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		throw std::runtime_error("bad date");
	Ymd	ymd
	{
		std::chrono::year{tm.tm_year + 1900} ,
		std::chrono::month{static_cast<unsigned>(tm.tm_mon + 1)} ,
		std::chrono::day{static_cast<unsigned>(tm.tm_mday)} ,
	};
	return ymd;
}

double BitcoinExchange::convertStrToValue(const std::string& str_value)
{
	static const std::string	valid = "-+.0123456789";

	if (str_value.find_first_not_of(valid) != std::string::npos
		|| str_value.find_first_of("+") != str_value.find_last_of("+")
		|| str_value.find_first_of("-") != str_value.find_last_of("-")
		|| str_value.find_first_of(".") != str_value.find_last_of("."))
		throw std::runtime_error("bad value");
	return std::stod(str_value);
}

void BitcoinExchange::loadDataBase(PriceMap& db, const std::string& filename)
{
	std::ifstream infile(filename);
	if (!infile)
		throw std::runtime_error("failed to open database");

	std::string line;

	if (!std::getline(infile, line) || line != "date,exchange_rate")
		throw std::runtime_error("invalid database format");

	while (std::getline(infile, line))
	{
		try
		{
			auto comma = line.find(',');
			if (comma == std::string::npos)
				throw std::runtime_error("invalid line format");

			Ymd date = convertStrToDate(line.substr(0, comma));
			double value = convertStrToValue(line.substr(comma + 1));

			db.emplace(date, value);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << ": " << line << '\n';
		}
	}
}


double BitcoinExchange::findValue(Ymd& tm_date)
{
	for (auto it = _priceDb.end(), begin = _priceDb.begin();;)
	{
		--it;
		if (!(it->first > tm_date))
			return it->second;
		if (it == begin)
			break;
	}
	throw std::runtime_error("no valid date in database");
}

static std::string formatDouble(double value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(10) << value;

	std::string s = oss.str();

	auto pos = s.find_last_not_of('0');
	if (pos != std::string::npos)
		s.erase(pos + (s[pos] == '.') + 1);

	return s;
}

void BitcoinExchange::exchange(const std::string& filename)
{
	std::ifstream infile(filename);
	if (!infile)
		throw std::runtime_error("failed to open input file");

	std::string line;

	if (!std::getline(infile, line) || line != "date | value")
		throw std::runtime_error("invalid input format");

	while (std::getline(infile, line))
	{
		try
		{
			auto sep = line.find(" | ");
			if (sep == std::string::npos)
				throw std::runtime_error("invalid line format");
			Ymd date = convertStrToDate(line.substr(0, sep));
			double value = convertStrToValue(line.substr(sep + 3));
			if (value < MIN || value > MAX)
				throw std::runtime_error("value out of range");
			double rate = findValue(date);
			double result = value * rate;
			std::cout << line.substr(0, sep) << " => " << formatDouble(value) << " = "  << formatDouble(result)	<< std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << ": " << line << "\n";
		}
	}
}
