#include "CLI/CLI.hpp"
#include "classes/configFile.h"
#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

void initializeApp() {
    ConfigFile cf = ConfigFile();

    if (cf.checkIfConfigFileExists() == false) {
        cf.createConfigFile();
    }

    cout << "RAD initalized in " << absolute(current_path()) << endl;
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
