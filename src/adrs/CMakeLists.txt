project(rad VERSION 0.0.1)

add_library(ADRs STATIC nygard.cpp)

target_link_libraries(ADRs fmt::fmt Markdown)

target_include_directories(ADRs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
