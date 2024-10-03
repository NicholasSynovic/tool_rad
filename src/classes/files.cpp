#include "files.h"
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

NygardADR::NygardADR(string title, path adrDirectory) {
    int adrNumber = 0;
    string adrFileTitle;

    for (path p : directory_iterator(adrDirectory)) {
        adrNumber += 1;
    }

    replace(title.begin(), title.end(), ' ', '-');

    for (char c : title) {
        adrFileTitle += tolower(c);
    }

    string rawFilename =
        ADR_FILENAME_SUFFIX + to_string(adrNumber) + "_" + adrFileTitle + ".md";

    filename = adrDirectory.append(rawFilename);
}

bool NygardADR::create() const {
    ofstream adr(filename);

    if (adr.is_open()) {
        adr.close();
        return 0;
    } else {
        return 1;
    }
}

ConfigFile::ConfigFile() {
    filepath = current_path().append(CONFIG_FILENAME);
    adrDirectory = current_path().append(CONFIG_ADR_DIRECTORY);

    DEFAULT_STATE = {{"adr_directory", adrDirectory}};
}

int ConfigFile::createConfigFile() const {
    if (exists(filepath)) {
        return 1;
    }

    ofstream cf;
    cf.open(filepath.c_str());

    if (cf.is_open()) {
        cf.close();
        return 0;
    } else {
        return 2;
    }
}

int ConfigFile::writeDefaultState() const {
    if (exists(filepath) == false) {
        return 1;
    }

    ofstream cf;
    cf.open(filepath);

    if (cf.is_open()) {
        cf << DEFAULT_STATE.dump(4) << endl;
        ;
        cf.close();
        return 0;
    } else {
        return 2;
    }
}
