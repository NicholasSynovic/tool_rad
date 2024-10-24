project(rad VERSION 0.0.1)

add_library(ConfigFile STATIC configFile.cpp)

target_link_libraries(ConfigFile nlohmann_json::nlohmann_json)

target_include_directories(ConfigFile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
