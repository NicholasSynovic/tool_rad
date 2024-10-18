#include <adrs.h>
#include <cstdio>
#include <gtest/gtest.h>
#include <markdown.h>

using namespace std;
using namespace filesystem;

TEST(NygardADRSuite, test_NygardADR) {
    Markdown::title t_test = {0, "Hello World"};
    NygardADR adr = NygardADR(0, "Hello World");

    EXPECT_EQ(adr.t.prefix, t_test.prefix);
    EXPECT_EQ(adr.t.title, t_test.title);
}

TEST(NygardADRSuite, test_GenerateFilename) {
    path test_directory = path("/test");

    NygardADR adr = NygardADR(0, "Hello World");

    path filename = adr.generateFilename(adr.t, test_directory);
    test_directory.append(ADR_FILENAME_SUFFIX + to_string(0) +
                          "_hello-world.md");

    EXPECT_EQ(filename, test_directory);
}
