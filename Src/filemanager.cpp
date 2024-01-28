#include "filemanager.h"
#include <iostream>
#include <exception>

struct dbfilesize_exception : public std::exception
{
    const char *what() const noexcept
    {
        return " the name should be less than 255 chars\n";
    }
};

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
    if(filename.length() > UINT8_MAX)
        throw dbfilesize_exception();
    stream << static_cast<uint8_t>(filename.length());
    stream << filename;

    m_file->close();
}
