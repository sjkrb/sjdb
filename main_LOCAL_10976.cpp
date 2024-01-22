#include <algorithm>
#include <bits/ranges_algo.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <regex>
#include <string>
#include <string_view>
#include <vector>
#include "Src/enums.h"

void print_prompt()
{
    std::cout << "db > ";
}

std::vector<std::string_view> tokenizer(std::string_view input)
{
    std::vector<std::string_view> tokens;

    for (const auto &in : input | std::ranges::views::split(' '))
    {
        tokens.emplace_back(std::string_view{in.begin(), in.end()});
        // std::cout << tokens.at(tokens.size() -1) << std::endl;
    }
    return tokens;
}

void get_input(std::string &input)
{
    std::getline(std::cin, input);

    if (input.length() == 0)
    {
        std::cout << "no command to execute";
    }
}

[[nodiscard]] Meta_cammand processMetaCommand(std::string_view input)
{
    if (input == ".exit")
    {
        std::cout << "have a good time :)";
        return Meta_cammand::Exit;
    }

    std::cout << "undeclared : " << input << '\n';
    return Meta_cammand::UnRecognized;
}

[[nodiscard]] Statement processStatement(std::string_view input)
{
    if (std::string_view{input.begin(), input.begin() + std::string{"insert"}.length()} == "insert")
        return Statement::Insert;
    if (std::string_view{input.begin(), input.begin() + std::string{"select"}.length()} == "select")
        return Statement::Select;
    return Statement::UnRecognized;
}

void handleStatement(const Statement &state, std::string_view input)
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

int main()
{
    std::string input{""};
    while (true)
    {
        print_prompt();
        get_input(input);
        if (input.at(0) == '.')
        {
            switch (processMetaCommand(input))
            {
            case Meta_cammand::Exit:
                exit(EXIT_SUCCESS);
                break;
            case Meta_cammand::UnRecognized:

                break;
            case Meta_cammand::CreateDataBase:

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

    return 0;
}
