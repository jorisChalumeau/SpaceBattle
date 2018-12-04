cmake_minimum_required(VERSION 3.5)
project(SpaceBattle)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.11.2/")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT5Core REQUIRED)
find_package(QT5Widgets REQUIRED)
find_package(QT5Gui REQUIRED)
find_package(QT5Network REQUIRED)
find_package(QT5Sql REQUIRED)
find_package(QT5Xml REQUIRED)
find_package(QT5PrintSupport REQUIRED)

add_executable(SpaceBattle controller/main.cpp model/Battleship.cpp model/Battleship.h model/Coordinate.cpp model/Coordinate.h model/Grid.cpp model/Grid.h model/Player.cpp model/Player.h)
target_link_libraries(SpaceBattle Qt5::Widgets Qt5::Core Qt5::Network Qt5::Sql
        ${Boost_LIBRARIES})