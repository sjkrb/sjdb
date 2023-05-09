#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <sys/types.h>

enum class Meta_cammand : uint8_t
{
    Exit,
    UnRecognized
};
enum class Statement : uint8_t
{
    Insert,
    Select,
    UnRecognized
};

void print_prompt()
{
    std::cout << "db > ";
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
    switch (state)
    {
    case Statement::Select: {
        std::cout << "this is the place that i should handle the select\n";
        auto split_string = input | std::ranges::views::split(' ');
        for (const auto &in : split_string)
        {
            std::cout << std::string_view{in.begin(), in.end()} << '\n';
        }
        break;
    }
    case Statement::Insert:
        std::cout << "this is the place that i should handle the insert\n";
        break;
    case Statement::UnRecognized:
        std::cout << "unrecognized command\n";
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
            }
        }
        else
        {
            handleStatement(processStatement(input), input);
        }
    }

    return 0;
}
