project(main.exe VERSION 0.0.1)

add_library(Files STATIC files.cpp)

target_link_libraries(Files nlohmann_json::nlohmann_json)

target_include_directories(Files PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
