#include "configFile.h"
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

ConfigFile::ConfigFile(path adrDirectory) {
    filepath = current_path().append(CONFIG_FILENAME);
    adrDirectory = current_path().append(adrDirectory.c_str());

    DEFAULT_STATE = {{"adr_directory", adrDirectory}};
}

int ConfigFile::createConfigFile() const {
    if (exists(filepath)) {
        return 1;
    }

    ofstream cf;
    cf.open(filepath.c_str());

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
        ;
        cf.close();
        return 0;
    } else {
        return 2;
    }
}
