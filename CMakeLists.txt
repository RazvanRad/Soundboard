cmake_minimum_required(VERSION 3.13)
project(Soundboard)

find_package(Boost 1.65.0 REQUIRED)

file(GLOB_RECURSE SOUNDBOARD_SOURCES "src/*.cpp" "src/*.c")

add_executable(soundboard_server ${SOUNDBOARD_SOURCES})
target_link_libraries(soundboard_server PUBLIC SDL2 SDL2_mixer bluetooth ${Boost_LIBRARIES} pthread)
target_include_directories(soundboard_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)