cmake_minimum_required(VERSION 3.23)
project(AzimuthBar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(AzimuthBar main.cpp
        src/AzimuthBar.cpp
        src/AzimuthBar.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui)

target_include_directories(AzimuthBar PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(AzimuthBar
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)



