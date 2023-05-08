#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <sys/types.h>

enum class Meta_cammand : uint8_t { Exit, UnRecognized };
enum class Statement : uint8_t { Insert, Select };

void print_prompt() { std::cout << "db > "; }

int get_input(std::string &input) {
  std::getline(std::cin, input);

  if (input.length() == 0) {
    std::cout << "no command to execute";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void processMetaCommand(std::string_view input) {}

int main() {
  std::string input{""};
  while (true) {
    print_prompt();

    int command = get_input(input);
    if (command == EXIT_FAILURE)
      return EXIT_FAILURE;
    if (input == ".exit") {
      std::cout << "have a good time :)";
      return EXIT_SUCCESS;
    } else {
      std::cout << "un recognized command\n";
    }
  }

  return 0;
}
