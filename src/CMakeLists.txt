project(main.exe VERSION 0.0.1)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(classes)

target_link_libraries(${PROJECT_NAME} ConfigFile)
target_link_libraries(${PROJECT_NAME} CLI11::CLI11)
