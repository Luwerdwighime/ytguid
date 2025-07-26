cmake_minimum_required(VERSION 3.10)
project(ytguid CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

cmake_policy(SET CMP0167 NEW)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(ytguid main.cpp)
target_include_directories(ytguid PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ytguid PRIVATE Boost::system)

