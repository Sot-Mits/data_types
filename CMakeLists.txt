project(data_types C)

file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

add_library(data_types ${SOURCES} ${HEADERS})

#Include the subdirectory for header files
target_include_directories(data_types PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

