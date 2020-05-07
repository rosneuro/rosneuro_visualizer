cmake_minimum_required(VERSION 2.8.3)
project(rosneuro_visualizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED COMPONENTS 
			 roscpp 
			 std_msgs
			 rosneuro_data
			 rosneuro_msgs)

find_package(PkgConfig)

SET(CMAKE_BUILD_TYPE RelWithDebInfo)
find_library(MCP_LIBRARIES mcpanel)
find_path(MCP_INCLUDE_DIRS mcpanel.h)


catkin_package(
  INCLUDE_DIRS 
	include
  LIBRARIES 
	${PROJECT_NAME}
  CATKIN_DEPENDS
  	roscpp
	std_msgs
	rosneuro_data
	rosneuro_msgs

  DEPENDS
)

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS} 
					${MCP_INCLUDE_DIRS}
					include
)

add_library(${PROJECT_NAME}
	src/neuroviz.cpp
)

target_link_libraries(${PROJECT_NAME} 
					  ${catkin_LIBRARIES} 
					  ${MCP_LIBRARIES}
)

add_dependencies(${PROJECT_NAME} 
				 ${catkin_EXPORTED_TARGETS}
)

#################
## Executables ##
#################
add_executable(neuroviz src/neuroviz.cpp)
target_link_libraries(neuroviz rosneuro_visualizer ${MCP_LIBRARIES})

