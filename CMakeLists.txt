cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
include_directories(${Qt6Widgets_INCLUDE_DIRS})
qt_standard_project_setup()


set(APP points-to-visit)

set(SRC_LIST
    src/main.cpp
    src/mainwindow.cpp
    src/canvas.cpp
    src/graph.cpp
    src/utils.cpp
    src/solver.cpp
    )

qt_add_executable(${APP} ${SRC_LIST})

target_link_libraries(points-to-visit PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)

