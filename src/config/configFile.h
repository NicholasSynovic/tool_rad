#include <filesystem>
#include <nlohmann/json.hpp>
#include <vector>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";          // Config filename
const string CONFIG_DEFAULT_ADR_TEMPLATE = "nygard"; // Config filename
const path CONFIG_ADR_DIRECTORY = path("docs/adr");  // ADR directory

class ConfigFile {
  private:
    json DEFAULT_STATE = json({{"adr_directory", CONFIG_ADR_DIRECTORY.string()},
                               {
                                   "adr_format",
                                   CONFIG_DEFAULT_ADR_TEMPLATE,
                               }}); // The content of the ADR config file

    vector<string> SCHEMA_KEYS = {"adr_directory", "adr_format"};

  public:
    path filepath; // Path to the ADR config file including the filename

    string adrFormat = "nygard"; // Default format of the ADR file

    ConfigFile();

    int createConfigFile() const;
    int writeDefaultState() const;

    path identifyNearestConfigFilePath() const;
    path findConfigFilePath(path directory) const;

    bool validateJSON(json data);
};

#endif
