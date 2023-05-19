#ifndef SHELL_H
#define SHELL_H

#include "database.h"
#include <memory>

class Shell
{
  public:
    Shell();
    static Shell *GetInstance();

  private:
    std::shared_ptr<DataBase> m_db;
    static std::unique_ptr<Shell> _shell;

};

#endif // SHELL_H
