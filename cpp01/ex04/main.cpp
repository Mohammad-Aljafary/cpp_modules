#include <iostream>
#include <fstream>

int check_args(int argc){
    if (argc != 4)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    if (!check_args(argc))
        return (1);
    std::fstream myFile(argv[1]);
    if (!myFile.is_open()){
        std::cerr << "file could not be opened" << std::endl;
        return (1);
    }
    std::string str1(argv[2]);
    std::string str2(argv[3]);

    myFile.close();
}