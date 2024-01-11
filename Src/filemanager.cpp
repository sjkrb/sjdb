#include "filemanager.h"
#include <iostream>

std::filebuf *FileManager::m_file{nullptr};

///////////////////////////// create database ////////////////////////////////////////////////////////////
void CreateDataBase::create(std::string_view filename)
{
    m_file = new std::filebuf();
    if(!m_file->open(std::filesystem::current_path().string() + '/' + std::string(filename) + ".db", std::ios::out | std::ios::binary))
        std::cout << "cant open the file";

    std::cout << std::filesystem::current_path().string() + std::string(filename) + ".db";
    std::ostream stream(m_file);
    stream << "SDJBHEADER";
    stream << static_cast<uint8_t>(filename.length());
    stream << filename;

    m_file->close();
}
