#include "CLI/CLI.hpp"
#include <iostream>

int main(int argc, char **argv) {
    CLI::App app{"RAD - Remember Architectural Decisions\nA tool to create and "
                 "manage your architectural decisions",
                 "rad"};

    app.add_subcommand("init", "Initialize RAD in the current directory");
    CLI11_PARSE(app, argc, argv);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
