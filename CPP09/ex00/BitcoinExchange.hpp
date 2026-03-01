#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _rates;
    static std::string  trim(const std::string& s);
    static bool         isValidDate(const std::string& date);
    static bool         parseValue(const std::string& token, double& out);
    void loadDatabase(const std::string& csvPath);
    bool getRateForDate(const std::string& date, double& outRate) const;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void processFile(const std::string& inputPath);
};

#endif
