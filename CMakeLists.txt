cmake_minimum_required(VERSION 2.8.8)
project(rosneuro_visualizer)

##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS 
			 roscpp 
			 std_msgs
			 rosneuro_data
			 rosneuro_msgs)

include_directories(include ${catkin_INCLUDE_DIRS})
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package()

##############################################################################
# Qt Environment
##############################################################################

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
#SET(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets QCustomPlot)

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)


QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})

include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5PrintSupport_INCLUDE_DIRS}
    )

add_definitions( -std=c++11 -fPIC)

##############################################################################
# Sources
##############################################################################

set( QT_SOURCES
	src/MainWindow.cpp
	src/DataThread.cpp
	src/NeuroPanel.cpp
	src/ScopePanel.cpp
	src/Buffer.cpp
	src/Palette.cpp
	src/neuroviz.cpp
    src/ui_panel.h
    src/ui_dialog_info.h
    include/rosneuro_visualizer/MainWindow.hpp
	include/rosneuro_visualizer/DataThread.hpp
	include/rosneuro_visualizer/NeuroPanel.hpp
	include/rosneuro_visualizer/ScopePanel.hpp
	include/rosneuro_visualizer/Buffer.hpp
	include/rosneuro_visualizer/Palette.hpp
    )

##############################################################################
# Binaries
##############################################################################

add_executable(neuroviz ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(neuroviz
    ${catkin_LIBRARIES}
    Qt5::Core
    Qt5::Widgets
	qcustomplot
)
