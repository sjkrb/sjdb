#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <vector>
#include <list>

struct Row
{
    int id {0};
    char* data{nullptr};
};

struct Table
{
    int id{0};
    std::string_view shape{""};
    std::vector<Row *> rows;
};

struct DataBase
{
    char* name{nullptr};
    std::list<Table *> tables;
};

#endif // STRUCTS_H
