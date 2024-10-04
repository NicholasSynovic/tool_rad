project(rad VERSION 0.0.1)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(config)
add_subdirectory(adrs)

target_link_libraries(${PROJECT_NAME} ADRs)
target_link_libraries(${PROJECT_NAME} ConfigFile)
target_link_libraries(${PROJECT_NAME} CLI11::CLI11)
