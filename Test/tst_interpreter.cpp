#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#define private public
#include "../Src/shell.h"

TEST_CASE("TOKENIZER") {
    REQUIRE(Shell::GetInstance()->tokenizer("") == std::vector<std::string_view>());
    REQUIRE(Shell::GetInstance()->tokenizer(" ") == std::vector<std::string_view>{"", ""});
    REQUIRE(Shell::GetInstance()->tokenizer("  ") == std::vector<std::string_view>{"", "", ""});
    REQUIRE(Shell::GetInstance()->tokenizer("sajjad karbasi") == std::vector<std::string_view>{"sajjad",
                                                                                               "karbasi"});
    REQUIRE(Shell::GetInstance()->tokenizer(" sajjad") == std::vector<std::string_view>{"", "sajjad"});
}
#undef private
