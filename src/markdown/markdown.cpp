#include "markdown.h"
#include <string>
#include <vector>

using namespace std;

Markdown::Markdown() {};

string Markdown::createTitle(Markdown::title t) {
    string title = to_string(t.prefix) + ". " + t.title;
    return title;
}

string Markdown::createSection(Markdown::section s) {
    string section = s.content;
    return section;
}

string Markdown::createDocument(Markdown::title t, vector<section> vs) {
    string document = "";

    document += "# " + Markdown::createTitle(t) + Markdown::contentSpacer;

    for (section s : vs) {
        document +=
            "## " + Markdown::createSection(s) + Markdown::contentSpacer;
    }

    return document;
}
