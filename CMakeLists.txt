

cmake_minimum_required(VERSION 3.14)
project(Raina C CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set (CMAKE_PREFIX_PATH "C:/Qt1/5.15.2/msvc2019_64/lib/cmake/Qt5" )



find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)

add_subdirectory(lib-ffmpeg)
add_subdirectory(Ui)

list(APPEND SOURCES
    main.cpp
    )

add_executable(Raina ${SOURCES})
target_link_libraries(Raina ffmpeg Ui Qt5::Gui Qt5::Core Qt5::Widgets  )

