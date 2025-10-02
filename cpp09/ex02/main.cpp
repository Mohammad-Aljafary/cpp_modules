#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    PmergeMe pmergeMe;
    try {
        pmergeMe.fillContainers(argv, argc);
        pmergeMe.sortAndDisplay();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}