
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

#define STD_DATE_FORMAT "YYYY-MM-DD"
#define PATH_PRICE_DB "./data.csv"

#define MIN 0
#define MAX 1000

typedef std::chrono::year_month_day Ymd;
typedef std::multimap<Ymd, double> PriceMap;

class BitcoinExchange
{
	private:
		PriceMap	_priceDb;

		Ymd    convertStrToDate(const std::string& date);
		double convertStrToValue(const std::string& value);
		void	loadDataBase(PriceMap& db, const std::string& filename);
		double	findValue(Ymd& str_date);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	exchange(const std::string& filename);
};

#endif
