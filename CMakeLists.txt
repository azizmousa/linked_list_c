# cmake version to be used
cmake_minimum_required( VERSION 3.19 )

# project name
set(PROJECT_NAME "linked_list")
project( ${PROJECT_NAME} )

# flags
set(CMAKE_CXX_FLAGS "-Wall -O2 -g")

# files
file(GLOB INCLUDE_DIRS "./include")
file(GLOB SRC_DIRS "./src/*.cpp")
# include
include_directories(${INCLUDE_DIRS})

# target
add_executable( ${PROJECT_NAME} ${SRC_DIRS} )

# external libs
