cmake_minimum_required(VERSION 3.8)
project(life_tracker_client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(qxtglobalshortcut REQUIRED)

include_directories(${Qt5Gui_PRIVATE_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp KeyPress.cpp KeyPress.h MyGlobalShortcutHandler.cpp MyGlobalShortcutHandler.h)

set(QT5_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Gui)

add_executable(life_tracker_client ${SOURCE_FILES})

target_link_libraries(life_tracker_client ${QT5_LIBRARIES} qxtglobalshortcut)