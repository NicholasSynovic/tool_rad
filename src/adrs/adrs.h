#include "fmt/core.h"
#include <filesystem>
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

class EdgeXADR : public ADR {
  public:
    Markdown::section s0 = {"Submitters"};
    Markdown::section s1 = {"Change Log"};
    Markdown::section s2 = {"Referenced Use Case(s)"};
    Markdown::section s3 = {"Context"};
    Markdown::section s4 = {"Proposed Design"};
    Markdown::section s5 = {"Considerations"};
    Markdown::section s6 = {"Decision"};
    Markdown::section s7 = {"Other Related ADRs"};
    Markdown::section s8 = {"References"};

    EdgeXADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3, s4, s5, s6, s7, s8};
    }
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
