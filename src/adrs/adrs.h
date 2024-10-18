#include "fmt/core.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <markdown.h>
#include <vector>

using namespace std;
using namespace filesystem;

#ifndef ADR_FILE_H
#define ADR_FILE_H

const string ADR_FILENAME_SUFFIX = "ADR_";

class ADR {
  public:
    path generateFilename(Markdown::title t, path adrDirectory);
    bool create(path adrDirectory);

    Markdown::title t;
    vector<Markdown::section> vs;
};

class NygardADR : public ADR {
  public:
    Markdown::section s0 = {"Context"};
    Markdown::section s1 = {"Decision"};
    Markdown::section s2 = {"Consequences"};

    NygardADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2};
    }
};

#endif
