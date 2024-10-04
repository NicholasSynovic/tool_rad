#include "adrs.h"
#include "fmt/core.h"
#include <algorithm>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

NygardADR::NygardADR(string title, path adrDirectory) {
    for (path p : directory_iterator(adrDirectory)) {
        adrNumber += 1;
    }

    adrTitle = to_string(adrNumber) + ". " + title;

    replace(title.begin(), title.end(), ' ', '-');

    for (char c : title) {
        adrFileTitle += tolower(c);
    }

    string rawFilename =
        ADR_FILENAME_SUFFIX + to_string(adrNumber) + "_" + adrFileTitle + ".md";

    filename = adrDirectory.append(rawFilename);
}

bool NygardADR::create() {
    string markdownContent = fmt::format("# {}\n\n## Context", adrTitle);

    ofstream adr(filename);

    if (adr.is_open()) {
        adr << markdownContent << endl;
        adr.close();
        return true;
    } else {
        return false;
    }
}
