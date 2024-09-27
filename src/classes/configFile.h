#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using namespace filesystem;

using json = nlohmann::json;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string FILENAME = ".rad";

class ConfigFile {
  private:
    path cwd;
    json config;

  public:
    ConfigFile();

    path configFilePath;

    bool checkIfConfigFileExists() const;
    void createConfigFile() const;
    void readConfigFile();
};

#endif
