#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string const &databaseFile);
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();

        void processInputFile(std::string const &inputFile) const;

    private:
        BitcoinExchange();

        std::map<std::string, double> _rates;

        void loadDatabase(std::string const &databaseFile);
        bool getRate(std::string const &date, double &rate) const;
};

#endif
