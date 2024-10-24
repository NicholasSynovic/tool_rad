#include "configFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace filesystem;

ConfigFile::ConfigFile() {
    /*
     * Classs to handle the creation, reading, and identification of RAD config
     * files.
     *
     * This constructor:
     *  sets the default filepath of where the RAD config file is expected to
     *  be and
     *  sets the default directory of where to store RAD created ADRs.
     *      This information is to be stored in the created `.rad.json` file.
     */
    filepath = current_path().append(CONFIG_FILENAME);
}

int ConfigFile::createConfigFile() const {
    /*
     * This function creates the configuration file.
     *
     * It is solely meant to create an empty .rad.json file at the filepath
     * path.
     *
     * Defualt content is added via the `writeDefaultState` function.
     *
     * The following logic is implemented:
     *  If the `filepath` already exists AND is a file, return 1.
     *  Else, create the file at `filepath`.
     *
     *  If the file is successfully created, return 0.
     *  Else, return 2.
     */
    if (exists(filepath) && is_regular_file(filepath)) {
        return 1;
    }

    ofstream cf;
    cf.open(filepath);

    if (cf.is_open()) {
        cf.close();
        return 0;
    } else {
        return 2;
    }
}

int ConfigFile::writeDefaultState() const {
    if (exists(filepath) == false) {
        return 1;
    }

    ofstream cf;
    cf.open(filepath);

    if (cf.is_open()) {
        cf << DEFAULT_STATE.dump(4) << endl;
        cf.close();
        return 0;
    } else {
        return 2;
    }
}

path ConfigFile::findConfigFilePath(path directory) const {
    /*
     * Given a directory return the path to the .rad.json file if it exists.
     * Else, return an empty path
     */
    for (path file : directory_iterator(directory)) {
        if (file.filename() == CONFIG_FILENAME && is_regular_file(file)) {
            return file;
        }
    }

    return path();
}

bool ConfigFile::validateJSON(json data) {
    for (string key : SCHEMA_KEYS) {
        if (data.contains(key) == false) {
            return false;
        }
    }

    return true;
}
