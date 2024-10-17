#include <string>
#include <vector>

using namespace std;

#ifndef MARKDOWN_H
#define MARKDOWN_H

class Markdown {
  public:
    struct title {
        int prefix;
        string title;
    };

    struct section {
        string content;
    };

    string contentSpacer = "\n\n";

    Markdown();
    string createTitle(title t);
    string createSection(section s);
    string createDocument(title t, vector<section> vs);
};

#endif
