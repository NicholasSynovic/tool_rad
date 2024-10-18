#include "fmt/core.h"
#include <filesystem>
#include <markdown.h>
#include <vector>

using namespace std;
using namespace filesystem;

#ifndef ADR_FILE_H
#define ADR_FILE_H

const string ADR_FILENAME_SUFFIX = "ADR_";

class NygardADR {
  private:
    Markdown::section s0 = {"Context"};
    Markdown::section s1 = {"Decision"};
    Markdown::section s2 = {"Consequences"};

    vector<Markdown::section> vs = {s0, s1, s2};

  public:
    Markdown::title t;

    NygardADR(int prefix, string title);
    path generateFilename(Markdown::title t, path adrDirectory);
    bool create(path adrDirectory);
};

#endif
