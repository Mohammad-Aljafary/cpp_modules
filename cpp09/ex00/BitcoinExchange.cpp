#include "BitcoinExchange.hpp"
#include <cstdlib>

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
            check_date_format(date);
            data[date] = value;
        }
        else {
            throw std::runtime_error("Invalid data format in line: " + line);
        }
    }
    file.close();
}

void trim_date(std::string& date)
{
    size_t start = date.find_first_not_of(" ");
    size_t end = date.find_last_not_of(" ");
    if (start != std::string::npos && end != std::string::npos) {
        date = date.substr(start, end - start + 1);
    }
}

void BitcoinExchange::check_date_format(const std::string& date) const
{
    std::string date_copy = date;
    trim_date(date_copy);

    if (date_copy.length() != 10 || date_copy[4] != '-' || date_copy[7] != '-') {
        throw std::runtime_error("Invalid date format: " + date);
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::runtime_error("Invalid date value: " + date);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw std::runtime_error("Invalid date value: " + date);
    }
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) {
            throw std::runtime_error("Invalid date value: " + date);
        }
    }
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

                check_date_format(date);

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