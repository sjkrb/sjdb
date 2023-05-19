#ifndef EMUMS_H
#define EMUMS_H

#include <cstdint>

enum class Meta_cammand : uint8_t
{
    Exit,
    CreateDataBase,
    RemoveDataBase,
    SelectDatabase,
    UnRecognized
};
enum class Statement : uint8_t
{
    Insert,
    Select,
    Delete,
    CreateTable,
    RemoveTable,
    UnRecognized
};

#endif
