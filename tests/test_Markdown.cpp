#include <cstdio>
#include <gtest/gtest.h>
#include <markdown.h>
#include <vector>

using namespace filesystem;

Markdown md = Markdown();

TEST(MarkdownSuite, test_CreateTitle) {
    Markdown::title t = {0, "Hello World"};
    EXPECT_EQ(md.createTitle(t), "0. Hello World");
}

TEST(ConfigFileSuite, test_CreateSection) {
    Markdown::section s = {"Hello World"};
    EXPECT_EQ(md.createSection(s), "Hello World");
}

TEST(ConfigFileSuite, test_CreateDocument) {
    Markdown::title t = {0, "Hello World"};

    Markdown::section s0 = {"Hello World"};
    Markdown::section s1 = {"Goodbye"};

    vector<Markdown::section> vs = {s0, s1};

    EXPECT_EQ(md.createDocument(t, vs),
              "# 0. Hello World\n\n## Hello World\n\n## Goodbye\n\n");
}
