#include <configFile.h>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

using namespace filesystem;

path TEST_FILENAME = current_path().append(CONFIG_FILENAME);

void createFile() {
    ofstream fp;
    fp.open(TEST_FILENAME);
    fp.close();
}

TEST(ConfigFileSuite, test_ConfigFile) {
    path cwd = current_path();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.filepath, TEST_FILENAME);
}

TEST(ConfigFileSuite, test_createConfigFile) {
    createFile();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.createConfigFile(), 1);

    remove(TEST_FILENAME);

    EXPECT_EQ(cf.createConfigFile(), 0);
}
