#include "adrs.h"
#include "fmt/core.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <markdown.h>

using namespace std;
using namespace filesystem;

NygardADR::NygardADR(int prefix, string title) { t = {prefix, title}; }

path NygardADR::generateFilename(Markdown::title t, path adrDirectory) {
    string filenameTitle = "";
    string title = t.title;

    replace(title.begin(), title.end(), ' ', '-');

    for (char c : title) {
        filenameTitle += tolower(c);
    }

    string rawFilename =
        ADR_FILENAME_SUFFIX + to_string(t.prefix) + "_" + filenameTitle + ".md";

    return adrDirectory.append(rawFilename);
}

bool NygardADR::create(path adrDirectory) {
    Markdown md = Markdown();

    string markdownContent = md.createDocument(t, vs);
    path filepath = generateFilename(t, adrDirectory);

    ofstream adr(filepath);

    if (adr.is_open()) {
        adr << markdownContent << endl;
        adr.close();
        return true;
    } else {
        return false;
    }
}
