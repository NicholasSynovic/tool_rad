#include <configFile.h>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

using namespace filesystem;

path CWD = absolute(current_path());

path createFile() {
    path cwd = absolute(current_path());
    path fp = cwd.append(CONFIG_FILENAME);

    ofstream testFile(fp);
    testFile.close();

    return fp;
}

void deleteFile(path fp) { remove(fp); }

TEST(ConfigFileSuite, test_createConfigFile) {
    ConfigFile cf = ConfigFile(path("docs/adr"));

    path tempFile = createFile();
    EXPECT_EQ(cf.createConfigFile(), 1);
    deleteFile(tempFile);

    EXPECT_EQ(cf.createConfigFile(), 0);
    deleteFile(cf.filepath);
}

TEST(ConfigFileSuite, test_writeDefaultState) {
    ConfigFile cf = ConfigFile(path("docs/adr"));

    EXPECT_EQ(cf.writeDefaultState(), 1);

    cf.createConfigFile();
    EXPECT_EQ(cf.writeDefaultState(), 0);
    deleteFile(cf.filepath);
}
