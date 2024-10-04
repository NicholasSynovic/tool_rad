#include "CLI/CLI.hpp"
#include "adrs/adrs.h"
#include "config/configFile.h"

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

json readConfigFile() {
    json data;

    ConfigFile cf = ConfigFile();

    if (exists(cf.filepath)) {
        ifstream jsonFile;
        jsonFile.open(cf.filepath);

        data = json::parse(jsonFile);
        jsonFile.close();
    } else {
        return json();
    }

    return data;
}

bool addADR(json configFileData, string title) {
    path adrDirectory = path(configFileData["adr_directory"]);

    if (!exists(adrDirectory)) {
        return false;
    }

    NygardADR adr = NygardADR(title, adrDirectory);

    return adr.create();
}

int main(int argc, char **argv) {
    CLI::App app{"RAD - Remember Architectural Decisions\nA tool to create and "
                 "manage your architectural decisions",
                 "rad"};
    app.require_subcommand(0, 1);

    // init subcommand
    CLI::App *initParser =
        app.add_subcommand("init", "Initialize RAD in the current directory");

    // add subcommand
    string title;
    CLI::App *addParser = app.add_subcommand("add", "Create a new ADR");
    addParser->add_option("-t,--title", title, "Title of the ADR")->required();

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
        json configFileData = readConfigFile();

        if (configFileData.is_null()) {
            return 1;
        }

        if (addADR(configFileData, title)) {
            return 0;
        } else {
            return 1;
        }
    }

    return 0;
}
