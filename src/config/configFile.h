#include <filesystem>
#include <sourcemeta/jsontoolkit/json.h>

using namespace std;
using namespace filesystem;

using json = sourcemeta::jsontoolkit::JSON;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string CONFIG_FILENAME = ".rad.json";         // Config filename
const string CONFIG_DEFAULT_ADR_FORMAT = "nygard";  // Default ADR template
const path CONFIG_ADR_DIRECTORY = path("docs/adr"); // ADR directory

class ConfigFile {
  private:
    json DEFAULT_STATE =
        json({{"adr_directory", json(CONFIG_ADR_DIRECTORY)},
              {"adr_format",
               json(CONFIG_DEFAULT_ADR_FORMAT)}}); // The content of the ADR
                                                   // config file

  public:
    path filepath; // Path to the ADR config file including the filename

    ConfigFile();

    int createConfigFile() const;
    int writeDefaultState() const;

    path identifyNearestConfigFilePath() const;
    path findConfigFilePath(path directory) const;
};

#endif
