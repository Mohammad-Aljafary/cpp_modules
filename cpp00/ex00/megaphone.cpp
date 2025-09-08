# include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; i <= argc - 1; i++)
        {
            std::string str;
            for(int j = 0; argv[i][j]; j++)
                str += toupper(argv[i][j]);
            std::cout << str;
        }
        std:: cout << std::endl;

    }
    return (0);
}