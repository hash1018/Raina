

cmake_minimum_required(VERSION 3.14)
project(Base C CXX)

set(Base_SOURCES
    RainaCore.cpp
   )

set(Base_HEADERS
    Singleton.h
    RainaCore.h
    )

add_library(Base
    ${Base_SOURCES}
    ${Base_HEADERS}
    )

target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})