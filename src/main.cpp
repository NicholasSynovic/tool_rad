#include "CLI/CLI.hpp"
#include <iostream>

int main(int argc, char **argv) {
  CLI::App app;
  CLI11_PARSE(app, argc, argv);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
