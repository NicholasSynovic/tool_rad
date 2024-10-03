#include <filesystem>

using namespace std;
using namespace filesystem;

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

class NygardADR {
  private:
    string unformattedTitle = "";
    string rawFilename = "ADR_";

  public:
    int adrNumber = 0;
    string title;
    path filename;

    NygardADR(string title, path adrDirectory);
    bool create() const;
};

#endif
