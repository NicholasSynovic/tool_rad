#include "fmt/core.h"
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
    int adrNumber = 0;

    string adrFileTitle;
    string adrTitle;
    path filename;

    NygardADR(string title, path adrDirectory);
    bool create();
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
