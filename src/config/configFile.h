#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";
const path CONFIG_ADR_DIRECTORY = path("./docs/adr");

class ConfigFile {
  private:
    json DEFAULT_STATE;

  public:
    path filepath;

    string adrFormat = "nygard";

    ConfigFile();

    int createConfigFile() const;
    int writeDefaultState() const;
    path identifyNearestConfigFilePath() const;
    path findConfigFilePath(path directory) const;
};

#endif
