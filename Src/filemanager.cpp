#include "filemanager.h"
#include <iostream>

std::filebuf *FileManager::m_file{nullptr};

///////////////////////////// create database ////////////////////////////////////////////////////////////

void CreateDataBase::operator()(std::string_view filename)
{
    m_file = new std::filebuf();
    if(!m_file->open(std::string(filename), std::ios::out))
        std::cout << "cant open the file";

    std::ostream stream(m_file);
    stream << "SDJBHEADER";
    stream << static_cast<uint8_t>(filename.length());
    stream << "NAME";

    m_file->close();
}
