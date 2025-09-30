#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float value;

        if (std::getline(ss, date, ',') && ss >> value) {
            data[date] = value;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }   
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float amount;
        if (std::getline(ss, date, '|') && ss >> amount) {
            try {
                float rate = getValue(date);
                if (amount < 0 || amount > 1000) {
                    std::ostringstream oss;
                    oss << amount;
                    throw std::runtime_error("Invalid amount: " + oss.str());
                }
                std::cout << date << " => " << amount << " = " << (amount * rate) << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error for date " << date << ": " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Error: Invalid input format in line: " << line << std::endl;
        }
    }
    file.close();
}

float BitcoinExchange::getValue(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date) {
        return it->second;
    }
    if (it == data.begin()) {
        throw std::runtime_error("No data available for date: " + date);
    }
    --it;
    return it->second;
}