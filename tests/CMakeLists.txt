project(tests VERSION 0.0.1)

add_executable(test_ConfigFile test_ConfigFile.cpp)
add_executable(test_Markdown test_Markdown.cpp)

target_link_libraries(test_ConfigFile ConfigFile GTest::gtest_main)
target_link_libraries(test_Markdown Markdown GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(test_ConfigFile test_Markdown)
