

cmake_minimum_required(VERSION 3.14)
project(Raina C CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_definitions(-DGL_SILENCE_DEPRECATION)

find_package(Qt5 COMPONENTS OpenGL Gui Core Widgets REQUIRED)

add_subdirectory(lib-ffmpeg)

if(APPLE)
    list(APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

elseif(WIN32)
    list(APPEND EXTRA_LIBS
        "-lglu32 -lopengl32"
    )
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")

else()
    list(APPEND EXTRA_LIBS
         "lGL -lGLU lX11"
    )

endif()



list(APPEND SOURCES
    main.cpp
    Ui/MainWindow.cpp
    Ui/MainWindow.h
    Ui/MainWindow.ui
    )

add_executable(Raina ${SOURCES})

target_link_libraries(Raina ffmpeg Qt5::OpenGL Qt5::Gui Qt5::Core Qt5::Widgets ${EXTRA_LIBS} )
