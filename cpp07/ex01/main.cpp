#include "iter.hpp"

void print(int &n) {
    std::cout << n << " ";
}

void print(char &c) {
    std::cout << c << " ";
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    iter(arr, 5, print);
    return 0;
}
