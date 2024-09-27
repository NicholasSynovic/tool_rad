#include <filesystem>

using namespace std;
using namespace filesystem;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

const string FILENAME = ".rad";

class ConfigFilev2 {
  private:
    bool testIfConfigFileExists() const;

  public:
    path filepath;
    path adrDirectory;

    ConfigFilev2(path adrDirectory);

    bool createConfigFile() const;
    bool writeDefaultState() const;
};

#endif
