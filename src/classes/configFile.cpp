#include "configFile.h"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

/*
 * When initializing the classs:
 * - identify the path for the config file
 * - identify where to store ADRs
 * - create the default configuration of data
 */

ConfigFile::ConfigFile(path adrDirectory) {
    fp = getCWD().append(FILENAME);
    adrDir = getCWD().append("docs/adr")
}

path getCWD() { return absolute(current_path()); }

bool ConfigFile::checkIfConfigFileExists() const {
    if (exists(configFilePath)) {
        return true;
    } else {
        return false;
    }
}

void ConfigFile::createConfigFile() const {
    ofstream file(configFilePath);

    file << defaultConfig.dump(4) << endl;

    file.close();
}

void ConfigFile::readConfigFile() {
    ifstream jf(configFilePath);
    config = json::parse(jf);
}
