#pragma once

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <stdexcept>

class BitcoinExchange {
   private:
    std::map<std::string, float> data;

   public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadData(const std::string& filename);
    void processInput(const std::string& filename) const;
    float getValue(const std::string& date) const;
};