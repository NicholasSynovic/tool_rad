project(rad VERSION 0.0.1)

add_library(ADRs STATIC adrs.cpp)

target_link_libraries(ADRs fmt::fmt)

target_include_directories(ADRs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
