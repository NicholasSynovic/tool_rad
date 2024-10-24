#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";         // Config filename
const path CONFIG_ADR_DIRECTORY = path("docs/adr"); // ADR directory

class ConfigFile {
  private:
    json DEFAULT_STATE; // The content of the ADR config file

  public:
    path filepath; // Path to the ADR config file including the filename

    string adrFormat = "nygard"; // Default format of the ADR file

    ConfigFile();

    int createConfigFile() const;
    int writeDefaultState() const;

    path identifyNearestConfigFilePath() const;
    path findConfigFilePath(path directory) const;
};

#endif
