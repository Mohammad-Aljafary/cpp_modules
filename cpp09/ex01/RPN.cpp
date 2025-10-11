#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : stk(other.stk) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        stk = other.stk;
    }
    return *this;
}

void RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stk.size() < 2) {
                throw std::runtime_error("Error: Not enough operands for operation " + token);
            }
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            int result;
            std::cout << a << std::endl;
            std::cout << b << std::endl;
            
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else {
                if (b == 0) {
                    throw std::runtime_error("Error: Division by zero");
                }
                result = a / b;
            }
            std::cout << "Result of " << a << " " << token << " " << b << " = " << result << std::endl;
            stk.push(result);
        } else {
            try {
                std::stringstream ss(token);
                int value = 0;
                ss >> value;
                if (ss.fail()) {
                    throw std::invalid_argument("Invalid token");
                }
                stk.push(value);
            } catch (const std::invalid_argument&) {
                throw std::runtime_error("Error: Invalid token " + token);
            } catch (const std::out_of_range&) {
                throw std::runtime_error("Error: Token out of range " + token);
            }
        }
    }

    if (stk.size() != 1) {
        throw std::runtime_error("Error: Invalid RPN expression");
    }

    std::cout << "Result: " << stk.top() << std::endl;
}