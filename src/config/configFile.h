#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";
const string CONFIG_ADR_DIRECTORY = "docs/adr";

class ConfigFile {
  private:
    json DEFAULT_STATE;

  public:
    path filepath;
    path adrDirectory;

    ConfigFile();

    int createConfigFile() const;
    int writeDefaultState() const;
};

#endif
