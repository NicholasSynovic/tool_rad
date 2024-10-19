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

class BusinessADR : public ADR {
  public:
    Markdown::section s0 = {"Title"};
    Markdown::section s1 = {"Status"};
    Markdown::section s2 = {"Evaluation Criteria"};
    Markdown::section s3 = {"Candidates To Consider"};
    Markdown::section s4 = {"Research And Analysis Of Each Candidate"};
    Markdown::section s5 = {"Recommendation"};

    BusinessADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3, s4, s5};
    }
};

class MADR : public ADR {
  public:
    Markdown::section s0 = {"Context And Problem Statement"};
    Markdown::section s1 = {"Decision Drivers"};
    Markdown::section s2 = {"Considered Options"};
    Markdown::section s3 = {"Decision Outcome"};
    Markdown::section s4 = {"Pros And Cons Of The Options"};
    Markdown::section s5 = {"Links"};

    MADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3, s4, s5};
    }
};

class TyreeADR : public ADR {
  public:
    Markdown::section s0 = {"Issue"};
    Markdown::section s1 = {"Decision"};
    Markdown::section s2 = {"Status"};
    Markdown::section s3 = {"Group"};
    Markdown::section s4 = {"Assumptions"};
    Markdown::section s5 = {"Constraints"};
    Markdown::section s6 = {"Positions"};
    Markdown::section s7 = {"Argument"};
    Markdown::section s8 = {"Implications"};
    Markdown::section s9 = {"Related Decisions"};
    Markdown::section s10 = {"Related Requirements"};
    Markdown::section s11 = {"Related Artifacts"};
    Markdown::section s12 = {"Related Principles"};
    Markdown::section s13 = {"Notes"};

    TyreeADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13};
    }
};

class PlanguageADR : public ADR {
  public:
    Markdown::section s0 = {"Tag"};
    Markdown::section s1 = {"Gist"};
    Markdown::section s2 = {"Requirement"};
    Markdown::section s3 = {"Rationale"};
    Markdown::section s4 = {"Priority"};
    Markdown::section s5 = {"Stakeholders"};
    Markdown::section s6 = {"Status"};
    Markdown::section s7 = {"Owner"};
    Markdown::section s8 = {"Author"};
    Markdown::section s9 = {"Revision"};
    Markdown::section s10 = {"Date"};
    Markdown::section s11 = {"Assumptions"};
    Markdown::section s12 = {"Risks"};
    Markdown::section s13 = {"Defined"};

    PlanguageADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13};
    }
};

class AlexandrianADR : public ADR {
  public:
    Markdown::section s0 = {"Prologue"};
    Markdown::section s1 = {"Discussion"};
    Markdown::section s2 = {"Solution"};
    Markdown::section s3{"Consequences"};

    AlexandrianADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3};
    }
};

class NygardADR : public ADR {
  public:
    Markdown::section s0 = {"Status"};
    Markdown::section s1 = {"Context"};
    Markdown::section s2 = {"Decision"};
    Markdown::section s3{"Consequences"};

    NygardADR(int prefix, string title) {
        t = {prefix, title};
        vs = {s0, s1, s2, s3};
    }
};

#endif
