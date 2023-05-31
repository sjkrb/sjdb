#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string_view>
#include <filesystem>
#include <fstream>

class FileManager
{
  public:
    FileManager() = default;

protected:
    static std::filebuf *m_file;
};


class CreateDataBase : public FileManager
{
public:
    CreateDataBase() = default;
    void operator()(std::string_view filename);
};

#endif // FILEMANAGER_H
