cmake_minimum_required(VERSION 3.1)
project(LThreadsTest)
include_directories(../include)
link_directories(../lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
add_executable(testthread testthread.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)
target_link_libraries(testthread ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(testthread libLThreads.a)