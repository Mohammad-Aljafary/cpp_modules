#pragma once


#include <iostream>
#include <fstream>

typedef struct lineRead 
{
    std::string line;
    struct lineRead *next;

} line;

line *newNode (std::string str);
void addBack(line** list, line* node);
void freeList(line** list);
void printList(line **list);