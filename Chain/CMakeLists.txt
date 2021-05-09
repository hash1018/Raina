

cmake_minimum_required(VERSION 3.14)
project(Chain C CXX)

set(Chain_SOURCES
    Chain.cpp
    Request.cpp
   )

set(Chain_HEADERS
     Chain.h
     Request.h
    )

add_library(Chain
    ${Chain_SOURCES}
    ${Chain_HEADERS}
    )

target_include_directories(Chain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
