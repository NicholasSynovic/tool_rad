add_test([=[ConfigFileSuite.test_ConfigFile]=]  /home/nicholas/Documents/projects/tool_rad/bin/test_ConfigFile [==[--gtest_filter=ConfigFileSuite.test_ConfigFile]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConfigFileSuite.test_ConfigFile]=]  PROPERTIES WORKING_DIRECTORY /home/nicholas/Documents/projects/tool_rad/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ConfigFileSuite.test_createConfigFile]=]  /home/nicholas/Documents/projects/tool_rad/bin/test_ConfigFile [==[--gtest_filter=ConfigFileSuite.test_createConfigFile]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConfigFileSuite.test_createConfigFile]=]  PROPERTIES WORKING_DIRECTORY /home/nicholas/Documents/projects/tool_rad/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ConfigFileSuite.test_findConfigFilePath]=]  /home/nicholas/Documents/projects/tool_rad/bin/test_ConfigFile [==[--gtest_filter=ConfigFileSuite.test_findConfigFilePath]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConfigFileSuite.test_findConfigFilePath]=]  PROPERTIES WORKING_DIRECTORY /home/nicholas/Documents/projects/tool_rad/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_ConfigFile_TESTS ConfigFileSuite.test_ConfigFile ConfigFileSuite.test_createConfigFile ConfigFileSuite.test_findConfigFilePath)
