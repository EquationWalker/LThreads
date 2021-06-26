cmake_minimum_required(VERSION 3.1)
project(LThreads)
include_directories(../../include)
aux_source_directory(./src LIB_SRCS)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Threads)

add_library(LThreads STATIC ${LIB_SRCS})
TARGET_LINK_LIBRARIES(LThreads ${CMAKE_THREAD_LIBS_INIT})