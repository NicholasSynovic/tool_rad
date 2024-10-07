#include <configFile.h>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

using namespace filesystem;

TEST(ConfigFileSuite, test_ConfigFile) {
    path cwd = current_path();
    ConfigFile cf = ConfigFile();

    EXPECT_EQ(cf.filepath, cwd.append(CONFIG_FILENAME));
    EXPECT_EQ(cf.adrDirectory, cwd.append(CONFIG_ADR_DIRECTORY));
}

TEST(ConfigFileSuite, test_createConfigFile) {}

TEST(ConfigFileSuite, test_writeDefaultState) {}

TEST(ConfigFileSuite, test_findConfigFilePath) {}

TEST(ConfigFileSuite, test_identifyNearestConfigFilePath) {}
