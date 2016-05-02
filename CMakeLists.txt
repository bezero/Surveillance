cmake_minimum_required(VERSION 3.3)
set(project_name "Surveillance")

# set the project name
project("${project_name}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG bin/)

# OpenCV package
find_package(OpenCV REQUIRED)

#add OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS} include/)

file(GLOB SOURCE_FILES src/*)
file(GLOB SHEADER_FILES include/*)

add_executable("${project_name}" ${SOURCE_FILES} ${SHEADER_FILES})
target_link_libraries("${project_name}" ${OpenCV_LIBS})