#include <filesystem>

using namespace std;
using namespace filesystem;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string FILENAME = ".rad";

class ConfigFile {
  private:
    path cwd;
    path configFilePath;
    string config;

  public:
    ConfigFile();

    bool checkIfConfigFileExists() const;
    void createConfigFile() const;
    void readConfigFile();
};

#endif
