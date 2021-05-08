

cmake_minimum_required(VERSION 3.14)
project(Raina C CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(WIN32)
set (CMAKE_PREFIX_PATH "C:/Qt1/5.15.2/msvc2019_64/lib/cmake/Qt5" )
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lan
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)

add_subdirectory(lib-ffmpeg)
add_subdirectory(Ui)
add_subdirectory(Base)
add_subdirectory(NotifyEvent)

list(APPEND SOURCES
    main.cpp
    )

    
if(WIN32)
add_executable(Raina WIN32 ${SOURCES})
else()
add_executable(Raina ${SOURCES})
endif()

target_link_libraries(Raina ffmpeg Ui Base NotifyEvent Qt5::Gui Qt5::Core Qt5::Widgets  )

