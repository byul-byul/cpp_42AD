#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "BitcoinExchange.hpp"

static std::string trim(std::string const &s)
{
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}

static bool isValidDate(std::string const &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    static int const daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    // Standard Gregorian leap year rule: divisible by 4, except centuries
    // not divisible by 400 (e.g. 1900 is not leap, 2000 is).
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (month == 2 && leap)
        maxDay = 29;

    return day >= 1 && day <= maxDay;
}

BitcoinExchange::BitcoinExchange(std::string const &databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _rates(other._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this == &other)
        return *this;
    _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(std::string const &databaseFile)
{
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));

        std::istringstream rateStream(rateStr);
        double rate;
        rateStream >> rate;
        if (rateStream.fail())
            continue;

        _rates[date] = rate;
    }
}

bool BitcoinExchange::getRate(std::string const &date, double &rate) const
{
    if (_rates.empty())
        return false;

    // upper_bound() gives the first entry strictly greater than `date`.
    // Stepping back one entry lands on the closest date <= `date` (the
    // subject requires the lower date, never the upper one). If that step
    // would go before begin(), no date in the database is old enough.
    std::map<std::string, double>::const_iterator it = _rates.upper_bound(date);
    if (it == _rates.begin())
        return false;
    --it;
    rate = it->second;
    return true;
}

void BitcoinExchange::processInputFile(std::string const &inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            if (line == "date | value")
                continue;
        }
        if (line.empty())
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::istringstream valueStream(valueStr);
        double value;
        valueStream >> value;
        if (valueStream.fail() || !valueStream.eof())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        double rate;
        if (!getRate(date, rate))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}
