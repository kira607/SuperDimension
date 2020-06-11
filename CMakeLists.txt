cmake_minimum_required(VERSION 3.10)
project(SuperDimension VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

aux_source_directory(src SOURCE)

add_executable(SuperDimension ${SOURCE} ${SOURCE_FILES})

target_link_libraries(SuperDimension sfml-graphics sfml-audio)

