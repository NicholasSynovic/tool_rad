#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";
const string CONFIG_ADR_DIRECTORY = "docs/adr";
const string ADR_FILENAME_SUFFIX = "ADR_";

class NygardADR {
  public:
    path filename;

    NygardADR(string title, path adrDirectory);
    bool create() const;
};

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
