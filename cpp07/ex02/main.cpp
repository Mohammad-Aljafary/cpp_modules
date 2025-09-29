#include "Array.hpp"

int main()
{
    try {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 2;
        }
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}