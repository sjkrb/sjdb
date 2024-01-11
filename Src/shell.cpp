#include <algorithm>
#include <bits/ranges_algo.h>
#include <string_view>
#include <string>
#include <iostream>
#include <ranges>
#include <iterator>
#include <list>

#include "filemanager.h"
#include "shell.h"

std::unique_ptr<Shell> Shell::_shell = std::unique_ptr<Shell>{nullptr};

Shell *Shell::GetInstance()
{
    if(_shell.get() == nullptr)
        _shell = std::unique_ptr<Shell> {new Shell};

    return _shell.get();
}

void Shell::run()
{
    std::string input{""};
    while (true)
    {
        print_prompt();
        get_input(input);
        if (input.at(0) == '.')
        {
            std::vector<std::string_view> metacommand = tokenizer(input);
            switch (processMetaCommand(metacommand.at(0)))
            {
            case Meta_cammand::Exit:
                exit(EXIT_SUCCESS);
                break;
            case Meta_cammand::UnRecognized:
                std::cout << "un recognize command : " << input << "\n";
                break;
            case Meta_cammand::CreateDataBase:
                CreateDataBase::create(metacommand.at(1));
                break;
            case Meta_cammand::RemoveDataBase:
                break;
            case Meta_cammand::SelectDatabase:
                break;
            }
        }
        else
        {
            handleStatement(processStatement(input), input);
        }
    }
}

void Shell::handleStatement(const Statement &state, std::string_view input)
{
    auto tokens = tokenizer(input);
    switch (state)
    {
    case Statement::Select: {
        break;
    }
    case Statement::Insert:
        std::cout << "this is the place that i should handle the insert\n";
        break;
    case Statement::UnRecognized:
        std::cout << "unrecognized command\n";
        break;
    case Statement::Delete:
        std::cout << "this is the place that i should delete the database and check befor deleting";
        break;
    case Statement::CreateTable:
        std::cout << "this is the place that i should create a table";
        break;
    case Statement::RemoveTable:
        std::cout << "this is the place that i should remove a table";
        break;
    }
}

Statement Shell::processStatement(std::string_view input)
{
    if (std::string_view{input.begin(), input.begin() + std::string{"insert"}.length()} == "insert")
        return Statement::Insert;
    if (std::string_view{input.begin(), input.begin() + std::string{"select"}.length()} == "select")
        return Statement::Select;
    return Statement::UnRecognized;
}

Meta_cammand Shell::processMetaCommand(std::string_view input)
{
    if (input == ".exit")
    {
        std::cout << "have a good time :)";
        return Meta_cammand::Exit;
    }

    if (input == ".create")
        return Meta_cammand::CreateDataBase;

    if (input == ".remove")
        return Meta_cammand::RemoveDataBase;

    if (input == ".select")
        return Meta_cammand::SelectDatabase;

    return Meta_cammand::UnRecognized;
}

void Shell::get_input(std::string &input)
{
    std::getline(std::cin, input);

    if (input.length() == 0)
    {
        std::cout << "no command to execute";
    }
}

std::vector<std::string_view> Shell::tokenizer(std::string_view input)
{
    std::vector<std::string_view> tokens;
    auto splitted = input | std::ranges::views::split(' ');

    for (const auto &in : splitted)
    {
        tokens.emplace_back(std::string_view{in.begin(), in.end()});
    }
    return tokens;
}

void Shell::print_prompt()
{
    std::cout << "db > ";
}



