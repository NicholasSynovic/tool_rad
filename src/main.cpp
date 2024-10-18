#include "CLI/CLI.hpp"
#include "adrs/adrs.h"
#include "config/configFile.h"
#include <fmt/core.h>
#include <markdown.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

int initializeApp() {
    /*
     * Intialize RAD in the current working directory
     *
     * If a `.rad.json` file exists, return 1
     * Else, create file
     *
     * If default state is written to the file, return 0
     * Else, return 2
     */
    ConfigFile cf = ConfigFile();

    if (exists(cf.filepath)) {
        cout << fmt::format("{} already exists", cf.filepath.c_str()) << endl;
        return 1;
    } else {
        cf.createConfigFile();
        cout << fmt::format("{} created", cf.filepath.c_str()) << endl;
    }

    if (cf.writeDefaultState() == 0) {
        cout << fmt::format("{} config written", cf.filepath.c_str()) << endl;
        return 0;
    } else {
        cout << fmt::format("{} error writing config", cf.filepath.c_str())
             << endl;
        return 2;
    }
}

path findConfigFile() {
    ConfigFile cf = ConfigFile();

    path cwd = current_path();

    while (true) {
        if (cwd != current_path().root_path()) {
            path potentialConfigFile = cf.findConfigFilePath(cwd);

            if (potentialConfigFile == path()) {
                cwd = cwd.parent_path();
            } else {
                return potentialConfigFile;
            }
        }

        else {
            break;
        }
    }

    return path();
}

json readConfigFile(ConfigFile cf) {
    ifstream jsonFile;
    json data;

    jsonFile.open(cf.filepath);
    data = json::parse(jsonFile);
    jsonFile.close();

    return data;
}

bool addADR(json configFileData, string title) {
    path adrDirectory = path(configFileData["adr_directory"]);

    if (!exists(adrDirectory)) {
        cout << "ERROR: Directory does not exist: " + adrDirectory.string()
             << endl;
        return false;
    }

    int adrPrefix = 0;
    for (const directory_entry entry : directory_iterator(adrDirectory)) {
        if (is_regular_file(entry)) {
            adrPrefix++;
        }
    }

    NygardADR adr = NygardADR(adrPrefix, title);

    if (adr.create(adrDirectory) == true) {
        cout << "Created ADR at "
             << adr.generateFilename(adr.t, adrDirectory).string() << endl;
        return true;
    } else {
        cout << "ERROR: Couldn't create ADR" << endl;
        return false;
    }
}

int main(int argc, char **argv) {
    /*
     * rad - Remeber Architectural Decisions
     *
     * Current options:
     *  init - Create a `.rad.json` file in the current working directory
     *  add - Create a new ADR in the directory listed in the nearest
     * `.rad.json` -t,--title: Title of the ADR
     */
    CLI::App app{"rad - Remember Architectural Decisions\nA tool to create and "
                 "manage your architectural decisions",
                 "rad"};
    app.require_subcommand(0, 1);

    // init subcommand
    CLI::App *initParser =
        app.add_subcommand("init", "Initialize rad in the current directory");

    // add subcommand
    string title;
    CLI::App *addParser = app.add_subcommand("add", "Create a new ADR");
    addParser->add_option("-t,--title", title, "Title of the ADR")->required();

    // Parse command line
    CLI11_PARSE(app, argc, argv);

    // If init subcommand was ran
    if (initParser->parsed()) {
        return initializeApp();
    }

    // If add subcommand was ran
    if (addParser->parsed()) {

        path nearestConfigFile = findConfigFile();
        if (nearestConfigFile.empty()) {
            cout << "ERROR: No config file (.rad.json) found." << endl;
            cout << "Run `rad init` to create the config file" << endl;
            return 1;
        }

        ConfigFile cf = ConfigFile();
        cf.filepath = nearestConfigFile;

        json data = readConfigFile(cf);
        return addADR(data, title);
    }

    cout << "Run `rad --help` for options" << endl;
    return 1;
}
