# include <iostream>

int main() {
    std:: string str =  "HI THIS IS BRAIN";
    std:: string* stringPTR = &str;
    std:: string& stringREF = str;

    std:: cout << "The address of the string: " << &str << std:: endl;
    std:: cout << "The address that is held by stringPTR: " << stringPTR << std:: endl;
    std:: cout << "The address that is held by stringREF: " << &stringREF << std:: endl;

    std:: cout << "The value of the string: " << str << std:: endl;
    std:: cout << "The value that is held by stringPTR: " << *stringPTR << std:: endl;
    std:: cout << "The value that is held by stringREF: " << stringREF << std:: endl;
    return (0);
}