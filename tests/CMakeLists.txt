project(tests VERSION 0.0.1)

add_executable(test_ConfigFile test_ConfigFile.cpp)

target_link_libraries(test_ConfigFile ConfigFile)
target_link_libraries(test_ConfigFile GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_ConfigFile)
