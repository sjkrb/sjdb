#ifndef SHELL_H
#define SHELL_H

#include "database.h"
#include "enums.h"
#include <vector>
#include <memory>

class Shell
{
  public:
    static Shell *GetInstance();

    void run();

  private:
    //vars
    std::shared_ptr<DataBase> m_db;
    static std::unique_ptr<Shell> _shell;

    //funcs
    Shell() = default;
    void handleStatement(const Statement &state, std::string_view input);
    [[nodiscard]] Statement processStatement(std::string_view input);
    [[nodiscard]] Meta_cammand processMetaCommand(std::string_view input);
    [[nodiscard]]bool get_input(std::string &input);
    std::vector<std::string_view> tokenizer(std::string_view input);
    void print_prompt();


};

#endif // SHELL_H
