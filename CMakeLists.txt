cmake_minimum_required(VERSION 3.1)
project(LThreads)
include_directories(./include)
aux_source_directory(./src LIB_SRCS)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++14")
FIND_PACKAGE(Threads)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)           #设置库文件的输出目录
add_library(LThreads STATIC ${LIB_SRCS})
TARGET_LINK_LIBRARIES(LThreads ${CMAKE_THREAD_LIBS_INIT})