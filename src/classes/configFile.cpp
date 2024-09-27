#include "configFile.h"
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

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

void ConfigFile::readConfigFile() { config = "Hello world"; }
