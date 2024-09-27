#include "configFile.h"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

ConfigFile::ConfigFile() {
    cwd = absolute(current_path());
    configFilePath = cwd.append(FILENAME);
}

bool ConfigFile::checkIfConfigFileExists() const {
    if (exists(configFilePath)) {
        return true;
    } else {
        return false;
    }
}

void ConfigFile::createConfigFile() const {
    ofstream file(configFilePath);
    file.close();
}

void ConfigFile::readConfigFile() {
    ifstream jf(configFilePath);
    config = json::parse(jf);
}
