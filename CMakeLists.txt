cmake_minimum_required(VERSION 3.10)
project(rayplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

include(FetchContent)
if(DEFINED ENV{CMAKE_LIBS_DIR})
    set(FETCHCONTENT_BASE_DIR "$ENV{CMAKE_LIBS_DIR}")
endif()

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

add_library(rayplus INTERFACE)
target_include_directories(rayplus INTERFACE ${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(rayplus_sources STATIC ${SOURCES})
target_link_libraries(rayplus_sources PRIVATE raylib rayplus)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(RAYPLUS_LITERAL_VERSION 0.1.0)
set(RAYPLUS_LITERAL_GIT_REPOSITORY "https://github.com/rkc137/rayplus.git")
set(RAYPLUS_LITERAL_LIB_GIT_TAG "v${RAYPLUS_LITERAL_VERSION}")
