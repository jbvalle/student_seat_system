cmake_minimum_required(VERSION 3.21)
project(gruppe_v C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES src/main.c)

add_executable(gruppe_v ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(gruppe_v ${GTK3_LIBRARIES})