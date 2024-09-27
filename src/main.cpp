#include "CLI/CLI.hpp"
#include "classes/configFile.h"
#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

bool initializeApp() {
    ConfigFile cf = ConfigFile();

    cout << cf.checkIfConfigFileExists() << endl;

    return cf.checkIfConfigFileExists();
}

int main(int argc, char **argv) {
    CLI::App app{"RAD - Remember Architectural Decisions\nA tool to create and "
                 "manage your architectural decisions",
                 "rad"};
    app.require_subcommand(0, 1);

    CLI::App *initParser =
        app.add_subcommand("init", "Initialize RAD in the current directory");

    CLI11_PARSE(app, argc, argv);

    if (initParser->parsed()) {
        initializeApp();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
