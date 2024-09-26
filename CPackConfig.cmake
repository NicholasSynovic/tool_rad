# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_DEB "OFF")
set(CPACK_BINARY_FREEBSD "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_NSIS "OFF")
set(CPACK_BINARY_RPM "OFF")
set(CPACK_BINARY_STGZ "ON")
set(CPACK_BINARY_TBZ2 "OFF")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_TXZ "OFF")
set(CPACK_BINARY_TZ "ON")
set(CPACK_BUILD_SOURCE_DIRS "/home/nicholas/Documents/projects/tool_rad;/home/nicholas/Documents/projects/tool_rad")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "gmock;gtest")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
set(CPACK_DEBIAN_PACKAGE_NAME "libcli11-dev")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/home/linuxbrew/.linuxbrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Project built using CMake")
set(CPACK_GENERATOR "STGZ;TGZ;TZ")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/nicholas/Documents/projects/tool_rad;Project;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "/home/nicholas/Documents/projects/tool_rad/_deps/cli11_proj-src/cmake")
set(CPACK_NSIS_DISPLAY_NAME "Project 2.3.2")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "Project 2.3.2")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/usr/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/home/nicholas/Documents/projects/tool_rad/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "https://github.com/CLIUtils/CLI11")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/home/nicholas/Documents/projects/tool_rad/_deps/cli11_proj-src/CLI11.CPack.Description.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Command line parser with simple and intuitive interface")
set(CPACK_PACKAGE_FILE_NAME "Project-2.3.2-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Project 2.3.2")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "Project 2.3.2")
set(CPACK_PACKAGE_NAME "Project")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "github.com/CLIUtils/CLI11")
set(CPACK_PACKAGE_VERSION "2.3.2")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "3")
set(CPACK_PACKAGE_VERSION_PATCH "2")
set(CPACK_READELF_EXECUTABLE "/usr/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/home/nicholas/Documents/projects/tool_rad/_deps/cli11_proj-src/LICENSE")
set(CPACK_RESOURCE_FILE_README "/home/nicholas/Documents/projects/tool_rad/_deps/cli11_proj-src/README.md")
set(CPACK_RESOURCE_FILE_WELCOME "/home/linuxbrew/.linuxbrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "/.git;/dist;/.*build.*;/\\.DS_Store;/.*\\.egg-info;/var;/azure-pipelines.yml;/.ci;/docs;/examples;/test_package;/book;/.travis.yml;.swp;/.all-contributorsrc;/.appveyor.yml;/.pre-commit.*yaml")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/nicholas/Documents/projects/tool_rad/CPackSourceConfig.cmake")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/nicholas/Documents/projects/tool_rad/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
