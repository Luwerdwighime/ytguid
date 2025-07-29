cmake_minimum_required(VERSION 3.16)
project(ytguid VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
  vendors/Crow/include
  vendors/asio/asio/include
  src
)
add_definitions(-DASIO_STANDALONE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Os")
set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE SOURCES
  src/*.cpp
)
add_executable(ytguid ${SOURCES})

