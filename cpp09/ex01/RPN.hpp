#pragma once

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN {
   private:
    std::stack<int> stk;

   public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void evaluate(const std::string& expression);
};