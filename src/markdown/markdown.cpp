#include "markdown.h"
#include <string>
#include <vector>

using namespace std;

Markdown::Markdown() {}; // TODO: Empty constructor; Do we need this?

string Markdown::createTitle(Markdown::title t) {
    /**
     * Convert a `Markdown::title struct` to a string as:
     * `{PREFIX}. {TITLE}`
     */
    string title = to_string(t.prefix) + ". " + t.title;
    return title;
}

string Markdown::createSection(Markdown::section s) {
    /**
     * Convert a `Markdown::section struct` to string as:
     * `{CONTENT}`
     */
    string section = s.content;
    return section;
}

string Markdown::createDocument(Markdown::title t, vector<section> vs) {
    /**
     * Wrapper around `createTitle` and `createSection` to create a single
     * string representing the content of a Markdown document
     * Example:
     *
     * `# {TITLE}\n\n## {SECTION}\n\n## {SECTION}`
     */
    string document = "";

    document += "# " + Markdown::createTitle(t) + Markdown::contentSpacer;

    for (section s : vs) {
        document +=
            "## " + Markdown::createSection(s) + Markdown::contentSpacer;
    }

    return document;
}
