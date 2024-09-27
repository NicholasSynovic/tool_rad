add_test([=[ConfigFileSuite.ConfigFile]=]  /home/nicholas/Documents/projects/tool_rad/bin/test_ConfigFile [==[--gtest_filter=ConfigFileSuite.ConfigFile]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConfigFileSuite.ConfigFile]=]  PROPERTIES WORKING_DIRECTORY /home/nicholas/Documents/projects/tool_rad/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_ConfigFile_TESTS ConfigFileSuite.ConfigFile)
