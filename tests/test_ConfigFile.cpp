#include <configFile.h>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

using namespace filesystem;

path TEST_FILENAME = current_path().append(CONFIG_FILENAME);
path TEST_DIRECTORY = current_path().append(CONFIG_ADR_DIRECTORY);

void createFile() {
    ofstream fp;
    fp.open(TEST_FILENAME);
    fp.close();
}

TEST(ConfigFileSuite, test_ConfigFile) {
    path cwd = current_path();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.filepath, TEST_FILENAME);
    ;
    EXPECT_EQ(cf.adrDirectory, TEST_DIRECTORY);
}

TEST(ConfigFileSuite, test_createConfigFile) {
    createFile();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.createConfigFile(), 1);

    remove(TEST_FILENAME);

    EXPECT_EQ(cf.createConfigFile(), 0);
}

TEST(ConfigFileSuite, test_findConfigFilePath) {
    createFile();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.findConfigFilePath(current_path()), TEST_FILENAME);

    remove(TEST_FILENAME);

    EXPECT_EQ(cf.findConfigFilePath(current_path()), path());
}
