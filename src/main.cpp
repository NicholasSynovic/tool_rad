#include "CLI/CLI.hpp"
#include "classes/configFile.h"
#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

bool initializeApp(path adrDirectory) {
    ConfigFile cf = ConfigFile(adrDirectory);

    if (cf.createConfigFile() != 0) {
        return false;
    }

    if (cf.writeDefaultState() == 0) {
        cout << "RAD initalized in " << absolute(current_path()) << endl;
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    CLI::App app{"RAD - Remember Architectural Decisions\nA tool to create and "
                 "manage your architectural decisions",
                 "rad"};
    app.require_subcommand(0, 1);

    CLI::App *initParser =
        app.add_subcommand("init", "Initialize RAD in the current directory");

    path initADRDirectory = path("docs/adr");
    initParser->add_option("-d,--directory", initADRDirectory,
                           "Directory to store ADRs in");

    CLI11_PARSE(app, argc, argv);

    if (initParser->parsed()) {
        initializeApp(initADRDirectory);
    }

    return 0;
}
