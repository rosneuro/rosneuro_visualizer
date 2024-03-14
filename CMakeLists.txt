cmake_minimum_required(VERSION 2.8.8)
project(rosneuro_visualizer)

##############################################################################
# Catkin
##############################################################################

find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)
find_library(RTF_LIBRARIES rtfilter)
find_path(RTF_INCLUDE_DIRS rtfilter.h)

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS 
			 roscpp 
			 std_msgs
			 rosneuro_data
			 rosneuro_msgs)


include_directories(include
					include/${PROJECT_NAME}/
					${catkin_INCLUDE_DIRS}
					${EIGEN3_INCLUDE_DIRS}
					${RTF_INCLUDE_DIRS})
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

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets PrintSupport)

##############################################################################
# QCustomPlot
##############################################################################
find_package(QCustomPlot REQUIRED)
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
add_definitions(${EIGEN3_DEFINITIONS})

##############################################################################
# Sources
##############################################################################

set( QT_SOURCES
	src/MainWindow.cpp
	src/EigenBuffer.cpp
	src/DataThread.cpp
	src/NeuroPanel.cpp
	src/ScopePanel.cpp
	src/TemporalPlot.cpp
	src/Palette.cpp
	src/FilterButterworth.cpp
	src/FilterCar.cpp
	src/FilterReference.cpp
	src/neuroviz.cpp
    src/ui_neuroviz.h
    src/ui_neuroviz_dialog_info.h
    src/ui_neuroviz_timescope.h
    include/rosneuro_visualizer/MainWindow.hpp
	include/rosneuro_visualizer/EigenBuffer.hpp
	include/rosneuro_visualizer/DataThread.hpp
	include/rosneuro_visualizer/NeuroPanel.hpp
	include/rosneuro_visualizer/ScopePanel.hpp
	include/rosneuro_visualizer/TemporalPlot.hpp
	include/rosneuro_visualizer/Palette.hpp
	include/rosneuro_visualizer/FilterButterworth.hpp
	include/rosneuro_visualizer/FilterCar.hpp
	include/rosneuro_visualizer/FilterReference.hpp
    )

##############################################################################
# GTest
##############################################################################

catkin_add_gtest(TestDataThread test/TestDataThread.cpp include/rosneuro_visualizer/DataThread.hpp src/DataThread.cpp)
target_link_libraries(TestDataThread ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestEigenBuffer test/TestEigenBuffer.cpp src/EigenBuffer.cpp)
target_link_libraries(TestEigenBuffer ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestFilterButterworth test/TestFilterButterworth.cpp src/FilterButterworth.cpp)
target_link_libraries(TestFilterButterworth ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestFilterCarVis test/TestFilterCar.cpp src/FilterCar.cpp)
target_link_libraries(TestFilterCarVis ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestFilterReference test/TestFilterReference.cpp src/FilterReference.cpp)
target_link_libraries(TestFilterReference ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestMainWindow test/TestMainWindow.cpp src/MainWindow.cpp include/rosneuro_visualizer/MainWindow.hpp
src/DataThread.cpp include/rosneuro_visualizer/DataThread.hpp src/NeuroPanel.cpp include/rosneuro_visualizer/NeuroPanel.hpp
src/ScopePanel.cpp include/rosneuro_visualizer/ScopePanel.hpp src/FilterButterworth.cpp include/rosneuro_visualizer/FilterButterworth.hpp
src/FilterCar.cpp include/rosneuro_visualizer/FilterCar.hpp src/FilterReference.cpp include/rosneuro_visualizer/FilterReference.hpp
src/TemporalPlot.cpp include/rosneuro_visualizer/TemporalPlot.hpp src/Palette.cpp include/rosneuro_visualizer/Palette.hpp
src/EigenBuffer.cpp include/rosneuro_visualizer/EigenBuffer.hpp)
target_link_libraries(TestMainWindow ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestNeuroPanel test/TestNeuroPanel.cpp src/NeuroPanel.cpp include/rosneuro_visualizer/NeuroPanel.hpp)
target_link_libraries(TestNeuroPanel ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestPalette test/TestPalette.cpp src/Palette.cpp)
target_link_libraries(TestPalette ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestScopePanel test/TestScopePanel.cpp src/ScopePanel.cpp include/rosneuro_visualizer/ScopePanel.hpp
src/NeuroPanel.cpp include/rosneuro_visualizer/NeuroPanel.hpp src/ui_neuroviz_timescope.h src/ui_neuroviz.h src/FilterButterworth.cpp
src/TemporalPlot.cpp src/Palette.cpp src/FilterCar.cpp src/FilterReference.cpp src/EigenBuffer.cpp src/DataThread.cpp
include/rosneuro_visualizer/EigenBuffer.hpp include/rosneuro_visualizer/DataThread.hpp include/rosneuro_visualizer/TemporalPlot.hpp
include/rosneuro_visualizer/Palette.hpp include/rosneuro_visualizer/FilterButterworth.hpp include/rosneuro_visualizer/FilterCar.hpp)
target_link_libraries(TestScopePanel ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

catkin_add_gtest(TestTemporalPlot test/TestTemporalPlot.cpp src/TemporalPlot.cpp include/rosneuro_visualizer/TemporalPlot.hpp
src/Palette.cpp include/rosneuro_visualizer/Palette.hpp src/EigenBuffer.cpp include/rosneuro_visualizer/EigenBuffer.hpp)
target_link_libraries(TestTemporalPlot ${GTEST_BOTH_LIBRARIES} pthread gmock ${Eigen3_LIBRARIES}
${catkin_LIBRARIES} ${RTF_LIBRARIES} ${RTF_LIBRARIES} Qt5::Core Qt5::Widgets ${QCustomPlot_LIBRARIES})

include_directories(${GTEST_INCLUDE_DIRS} gmock pthread include/ include/${PROJECT_NAME}/)

##############################################################################
# Binaries
##############################################################################

add_executable(neuroviz ${Eigen3_LIBRARIES} ${RTF_LIBRARIES} ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(neuroviz
    ${catkin_LIBRARIES}
	${Eigen3_LIBRARIES}
	${RTF_LIBRARIES}
    Qt5::Core
    Qt5::Widgets
	${QCustomPlot_LIBRARIES}
)

#################
##   Install   ##
#################
install(TARGETS neuroviz
	RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
        )

