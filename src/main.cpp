#include "CLI/CLI.hpp"
#include "classes/configFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

bool initializeApp() {
    ConfigFile cf = ConfigFile();

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

bool addADR() {
    json data;

    ConfigFile cf = ConfigFile();

    if (exists(cf.filepath)) {
        ifstream jsonFile;
        jsonFile.open(cf.filepath);

        data = json::parse(jsonFile);
        jsonFile.close();
    } else {
        return false;
    }

    path adrDirectory = path(data["adr_directory"]);

    if (exists(adrDirectory)) {
        ofstream adrFile(adrDirectory.append(".helloworld"));
        cout << "Hello world" << endl;
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

    // init subcommand
    CLI::App *initParser =
        app.add_subcommand("init", "Initialize RAD in the current directory");

    CLI::App *addParser = app.add_subcommand("add", "Create a new ADR");

    // Parse command line
    CLI11_PARSE(app, argc, argv);

    // If init subcommand was ran
    if (initParser->parsed()) {
        if (initializeApp()) {
            return 0;
        } else {
            return 1;
        }
    }

    // If add subcommand was ran
    if (addParser->parsed()) {
        addADR();
        return 0;
    }

    return 0;
}
