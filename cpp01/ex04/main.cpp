#include "Sed.hpp"

int check_args(int argc){
    if (argc != 4)
        return (0);
    return (1);
}

void writeToFile(line* list, std::ofstream& file) {
    while (list) {
        file << list->line << "\n";
        list = list->next;
    }
}

void modifyLines(line *list, std::string str1, std::string str2){
    size_t pos = 0;
    line *temp = list;
    while (temp){
        pos = 0; 
        while (pos != std::string::npos)
        {
            pos = temp->line.find(str1, pos);
            if (pos == std::string::npos)
                break;
            temp->line.erase(pos, str1.length());
            temp->line.insert(pos, str2);
            pos += str2.length();
        }
        temp = temp->next;
    }
}

line* readFile(std::fstream& file) {
    line* list = NULL;
    std::string charRead;

    while (std::getline(file, charRead)) {
        line* node = newNode(charRead);
        if (!node)
        {
            std::cerr << "Bad Allocation" << std::endl;
            freeList(&list);
            return (NULL);
        }
        addBack(&list, node);
    }
    if (!list)
    {
        std::cerr << "Empty file" << std::endl;
        return (NULL);
    }
    return (list);
}

int main(int argc, char **argv)
{
    line* list = NULL;

    if (!check_args(argc))
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 1;
    }

    std::fstream myFile(argv[1]);
    if (!myFile.is_open()) {
        std::cerr << "file could not be opened" << std::endl;
        return 1;
    }
    std::string str1(argv[2]);
    std::string str2(argv[3]);
    std::string outputFile = std::string(argv[1]) + ".replace";
    list = readFile(myFile);
    myFile.close();
    if (!list)
        return 1;
    std::ofstream output(outputFile.c_str());
    if (!output.is_open()) {
        std::cerr << "could not create output file" << std::endl;
        return 1;
    }
    modifyLines(list, str1, str2);
    writeToFile(list, output);
    output.close();
    freeList(&list);
    return 0;
}
