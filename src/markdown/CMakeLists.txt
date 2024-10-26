project(rad VERSION 0.0.1)

add_library(Markdown STATIC markdown.cpp)

target_include_directories(Markdown PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
