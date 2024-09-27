#include <configFile.h>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

using namespace filesystem;

path createFile() {
    path cwd = absolute(current_path());
    path fp = cwd.append(FILENAME);

    ofstream testFile(fp);
    testFile.close();

    return fp;
}

void deleteFile(path fp) { remove(fp); }

TEST(ConfigFileSuite, TestForConfigFile) {
    ConfigFile cf = ConfigFile();

    path cfp = createFile();
    EXPECT_TRUE(cf.checkIfConfigFileExists());

    deleteFile(cfp);
    EXPECT_FALSE(cf.checkIfConfigFileExists());
}

TEST(ConfigFileSuite, TestCreateFile) {
    ConfigFile cf = ConfigFile();

    cf.createConfigFile();

    EXPECT_TRUE(cf.checkIfConfigFileExists());

    deleteFile(cf.configFilePath);
    EXPECT_FALSE(cf.checkIfConfigFileExists());
}
