#include <string>
#include <vector>

using namespace std;

#ifndef MARKDOWN_H
#define MARKDOWN_H

class Markdown {
  public:
    struct title {
        /**
         * Title of the document that will be used both in the:
         *  - Markdown file name (e.g., `ADR_{PREFIX}_{TITLE}.md`), and
         *  - Title of the document (e.g., `# {PREFIX}. {TITLE}`).
         */
        int prefix;
        string title;
    };

    struct section {
        /**
         * A specific section of the Markdown document.
         * Example: `## Hello World`
         */
        string content;
    };

    string contentSpacer = "\n\n"; // Content to space out titles and sections

    Markdown(); // TODO: Empty constructor; figure out if this is necessary
    string createTitle(title t);     // Convert struct to string
    string createSection(section s); // Convert struct to string

    // Wrapper around createTitle and createSection calls
    string createDocument(title t, vector<section> vs);
};

#endif
