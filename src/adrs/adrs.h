#include "fmt/core.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

#ifndef ADR_FILE_H
#define ADR_FILE_H

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

#endif
