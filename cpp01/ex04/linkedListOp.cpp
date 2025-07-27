# include "Sed.hpp"

line *newNode (std::string str){
    line *node = new line;

    node->line = str;
    node->next = NULL;
    return (node);
}

void addBack(line** list, line* node) {
    if (!*list) {
        *list = node;
    } else {
        line* temp = *list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void freeList(line** list) {
    line* current = *list;
    while (current) {
        line* next = current->next;
        delete current;
        current = next;
    }
    *list = NULL;
}

void printList(line **list){
    line *temp = *list;
    while (temp){
        std::cout << temp->line << std::endl;
        temp = temp->next;
    }
}
